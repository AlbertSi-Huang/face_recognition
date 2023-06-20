#include "XFaceDetectThread.h"
#include "alg_face_detect.h"
#include <QDebug>
#include <fstream>
#include <qtextcodec.h>
#include <QDateTime>
#include <QFile>
#include "alg_coat_detect.h"
#include "alg_helmet_detect.h"
#include "sqlite_white.h"
#include "DateTimeHelper.h"
#include "FileCommonHelper.h"
#include "config_file.h"

XFaceDetectThread::XFaceDetectThread()
    : _bInited(false),_pauseSendDetect(false),_pauseDetect(false)
{
//    start();
}

void XFaceDetectThread::onInited(int nInit)
{
    if(nInit == 0)
    {
         _bInited = true;
    }
}

void XFaceDetectThread::onCaptureImg(cv::Mat mat)
{
    _mutexImg.lock();
    mat.copyTo(_mat);
    _mutexImg.unlock();
}

bool XFaceDetectThread::GetFea(cv::Mat img, unsigned char szFea[8192])
{
    RECT rcInfo[100];
    FacePointInfo ptInfo[100];
    int nRet = CAlgFaceDetect::signle().faceAlgDetect(img.data, img.cols, img.rows, rcInfo, ptInfo);//人脸检测
    if(nRet<1)
    {
        return false;
    }

    bool bRet = CAlgFaceDetect::signle().faceAlgGetFea(img.data,img.cols,img.rows,ptInfo[0],szFea);
    return bRet;
}




void XFaceDetectThread::onSendStop(bool bStop)
{
    _pauseSendDetect = bStop;
}

void XFaceDetectThread::onDetectStop(bool bStop)
{
    _pauseDetect = bStop;
}

bool XFaceDetectThread::GetFea(std::string strName, unsigned char szFea[8192])
{
    cv::Mat img = cv::imread(strName.c_str());
    return GetFea(img,szFea);
}

bool XFaceDetectThread::getFeaFromFile(std::string fileFullName,SFaceFeatureInfo& info)
{
    string fileName = CFileCommonHelper::getNoPathFile(fileFullName);
    string fileOnleName = CFileCommonHelper::getOnlyFileName(fileName);
    vector<string> fileNameInfo = CFileCommonHelper::splitString(fileOnleName,"_");
    if(fileNameInfo.size()>3){
        SFaceFeatureInfo info;
        info.name = fileNameInfo[0];
        info.cell = fileNameInfo[1];
        info.group = fileNameInfo[2];
        info.tick = fileNameInfo[3];
        unsigned char* data = new unsigned char[8192];
        FILE* fp = fopen(fileFullName.c_str(),"rb+");
        fread(data,1,8192,fp);
        memcpy(info.fea,data,8192);
        delete data;data = nullptr;
        fclose(fp);
        return true;
    }
    return false;
}

//加载白名单到内存，开始时候执行一次
void XFaceDetectThread::loadFea()
{
    string currPath = CFileCommonHelper::getCurrentPath();
    string writePath = currPath + "\\resource\\write\\";

    std::vector<std::string> writeFullImgs;
    std::vector<std::string> writeImgs;
    CFileCommonHelper::getFileNames(writePath,writeFullImgs,writeImgs);

    for(int i = 0;i<writeFullImgs.size();++i)
    {
        SFaceFeatureInfo info;
        bool bRet = getFeaFromFile(writeFullImgs[i],info);
        if(bRet)
        {
            _writeLists.push_back(info);
        }
    }

}

bool XFaceDetectThread::GetFea(cv::Mat img,FacePointInfo faceInfo[1024],unsigned char* szFea[8192],int nFace)
{
    bool bRet = true;
    for(int i = 0;i<nFace;++i)
    {
        bRet =CAlgFaceDetect::signle().faceAlgGetFea(img.data,img.cols,img.rows,faceInfo[i],szFea[i]);
    }
    return true;
}

std::vector<string> XFaceDetectThread::readTxt(string fileName)
{

    vector<string> lines;
    ifstream ifs(fileName.c_str());  //读取文件
        if(!ifs.good())
        {
            cerr << "ifstream open file error!\n";
            return lines;
        }
        string line;
        while(getline(ifs, line))    //获取每一行数据
        {
            lines.push_back(line);   //将每一行依次存入到vector中
//            cout << line << endl;    //顺便打印一下这一行
        }
        ifs.close();
        return lines;
}

void XFaceDetectThread::run()
{

    string currPath = CFileCommonHelper::getCurrentPath();
    string writeImg = currPath + "\\resource\\whiteImg\\";
    string write = currPath + "\\resource\\white\\";
    string writeBak = currPath + "\\resource\\whiteImgBak\\";
    string record = currPath + "\\resource\\record\\";
    unsigned char* szFea = new unsigned char[8192];
    unsigned char* currentFea = new unsigned char[8192];
    unsigned char* lastFea = new unsigned char[8192];
    unsigned char** detectFeas = new unsigned char*[64];
    for(int i = 0;i<64;++i)
    {
        detectFeas[i] = new unsigned char[8192];
    }
    long lastTick = GetTickCount64();
    bool bHaveFace = false;
    int nLoopNoFace = 0;
    bool bRet = CSqliteWhite::signle()->openWhiteDb();
    std::cout <<"open db " <<bRet<<std::endl;
    CSqliteWhite::signle()->loadWhiteLists(_writeLists);
    std::cout <<"_writeLists size = " << _writeLists.size() <<std::endl;
    QDateTime lastTime=  QDateTime::currentDateTime();
    SFaceFeatureInfo noFaceinfo;
    SFaceFeatureInfo havFaceinfo;
    RECT* rc = new RECT[1024];
    FacePointInfo* fpInfo = new FacePointInfo[1024];
    try {
        while(true)
        {
            QThread::usleep(100);
            if(!_bInited)
            {
                continue;
            }
            if(_pauseDetect)
            {
                continue;
            }
            if(_mat.empty())
            {
                continue;
            }
            cv::Mat matCurrent;
            _mutexImg.lock();
            _mat.copyTo(matCurrent);
            _mutexImg.unlock();

            int nFind = CAlgFaceDetect::signle().faceAlgDetect(matCurrent.data,matCurrent.cols,
                                                   matCurrent.rows,rc,fpInfo);

            if(nFind > 0)
            {
                emit detectFaceRect(rc,nFind);
                int nMinLeftFace = matCurrent.cols / 20;
                // 判断人脸是否在屏幕较中间范围内
                if((rc[0].left < nMinLeftFace) || (rc[0].right >matCurrent.cols-nMinLeftFace)
                        )
                {
                    continue;
                }
                // 提特征值并且比对
                bool bRetGetFea = GetFea(matCurrent,fpInfo, detectFeas,nFind);

                if(bRetGetFea)
                {
                    if(nFind == 1)
                    {
                        memcpy(lastFea,detectFeas[0],8192);
                        if(bHaveFace)
                        {
                            float f = CAlgFaceDetect::signle().faceAlgCompare(detectFeas[0],lastFea);
                            if(f>95)
                            {
                                QDateTime nowTime = QDateTime::currentDateTime();
                                qint64 intervalTime = lastTime.secsTo(nowTime);
                                if(intervalTime<6){
                                    continue;
                                }
                            }
                        }
                    }

                    //找一个最大的
                    float fMax = 0;
                    int iMax = -1;
                    for(int i = 0;i<_writeLists.size();++i)
                    {
                        float f = CAlgFaceDetect::signle().faceAlgCompare(detectFeas[0],_writeLists[i].fea);
                        if(f> fMax)
                        {
                            fMax = f;
                            iMax = i;
                        }
                    }

                    int score = CConfig::signle()->getScore();
                    CoatRectInfo coatInfo[10];
                    HelmetRectInfo helmetInfo[10];
    //                cv::imshow("matCurrent",matCurrent);
    //                cv::waitKey(30);
                    int nCoatRet = CAlgCoatDetct::signle().coatAlgDetect(matCurrent.data,matCurrent.cols,
                                                          matCurrent.rows,coatInfo);

                    qDebug() << "nCoatRet = " << nCoatRet;

                    if(nCoatRet>0)
                    {
                        // coatInfo[0].nType == 1 表示未佩戴安全帽
                        qDebug() << coatInfo[0].nType << "," << coatInfo[0].nScroe;
                        if(coatInfo[0].nType == 0){
                            // 有佩戴
                            nCoatRet = 1;
                        }else
                        {
                            // 未佩戴
                            nCoatRet = 2;
                        }
                    }else{
                        nCoatRet = 2;
                    }

                    long t1 = GetTickCount64();
                    int nHelmetRet  = CAlgHelmetDetect::signle().HelmetAlgDetect(matCurrent.data,matCurrent.cols,
                                                                                 matCurrent.rows,helmetInfo);
                    long t2 = GetTickCount64();
                    string strLog = "helmet detect tick = " + to_string(t2-t1);
                    CDateTimeHelper::writeSimpleLog(strLog);
                    std::cout <<strLog <<std::endl;
                    if(nHelmetRet>0)
                    {
                        qDebug() << helmetInfo[0].nType << "," << helmetInfo[0].nScroe;
                        if(helmetInfo[0].nType == 0){
                            nHelmetRet = 1;
                        }else
                        {
                            nHelmetRet = 2;
                        }
                    }else{
                        nHelmetRet = 2;
                    }
                    qDebug() << "nHelmetRet = " << nHelmetRet;
                    long nowTick = GetTickCount64();
                    if(nowTick - lastTick > 2000)
                    {
                        int nMinScore = score - 20;

                        if(fMax>score)
                        {
                            //比对成功
                            // 规定时间内，同一个人不发送信号
                            std::cout << "read send signle success " << iMax<< std::endl;
                            havFaceinfo.cell =_writeLists[iMax].cell;
                            havFaceinfo.group = _writeLists[iMax].group;
                            havFaceinfo.name = _writeLists[iMax].name;
                            havFaceinfo.jobs = _writeLists[iMax].jobs;
                            havFaceinfo.tempImg = _writeLists[iMax].tempImg;
//                            cv::Mat matCopy;matCurrent.copyTo(matCopy);
//                            cv::rectangle(matCopy,cv::Rect(rc[0].left,rc[0].top,rc[0].right - rc[0].left,rc[0].bottom - rc[0].top),(255,0,0),2);
//                            string tickNow = CDateTimeHelper::getDateTimeString(0);
//                            string fileName = record + tickNow + ".jpg";
//                            cv::imwrite(fileName.c_str(),matCopy);
                            emit compareFace(true,havFaceinfo,matCurrent,nCoatRet,nHelmetRet);
                            lastTick = GetTickCount64();
                        }else if(fMax<nMinScore)
                        {
//                          std::cout << "read send signle failed " << std::endl;
//                            cv::Mat matCopy;matCurrent.copyTo(matCopy);
//                            cv::rectangle(matCopy,cv::Rect(rc[0].left,rc[0].top,rc[0].right - rc[0].left,rc[0].bottom - rc[0].top),(255,0,0),2);
//                            string tickNow = CDateTimeHelper::getDateTimeString(0);
//                            string fileName = record + tickNow + ".jpg";
//                            cv::imwrite(fileName.c_str(),matCopy);
                            emit compareFace(false,noFaceinfo,matCurrent,nCoatRet,nHelmetRet);
                            lastTick = GetTickCount64();
                        }

                    }

                }

                bHaveFace = true;
                lastTime = QDateTime::currentDateTime();
            }else{
                bHaveFace = false;
                nLoopNoFace++;
                if(nLoopNoFace>=50)
                {
                    nLoopNoFace = 0;
                    onCheckWhiteListsFile();
                }
            }

        }
    }  catch (exception e) {
        std::cout << "exception " << e.what() <<std::endl;

    }

}


bool XFaceDetectThread::onCheckWhiteListsFile()
{
    string currPath = CFileCommonHelper::getCurrentPath();
    string writeImg = currPath + "\\resource\\whiteImg\\";
    string writeBak = currPath + "\\resource\\whiteImgBak\\";
    bool bExist = CFileCommonHelper::fileExist(writeImg + "whiteList.txt");

    if(bExist)
    {
        QTextCodec* codec = QTextCodec::codecForName("utf-8");//添加编码格式
        std::vector<string> vecWhiteCont = readTxt(writeImg + "whiteList.txt");
        unsigned char szFea[8192] = {0};
        for(int i = 0;i<vecWhiteCont.size();++i){
            QString qstr = codec->toUnicode(vecWhiteCont[i].c_str());
            QStringList qList = qstr.split("_");
            string str = qstr.toLocal8Bit().constData();
//            string stdStr = CFileCommonHelper::UTF8ToString(str);

            vector<string> vecFile =CFileCommonHelper::splitString(str,"_");
            if(vecFile.size() != 5)
            {
                continue;
            }
            string whiteImgFullPath = writeImg + vecFile[4];
            if(!CFileCommonHelper::fileExist(whiteImgFullPath)){
                continue;
            }

            bool bRet = GetFea(whiteImgFullPath,szFea);
            if(bRet)
            {
                SFaceFeatureInfo info;
                string timeTick = CDateTimeHelper::getDateTimeString(0);
                string copyAfterFileName = CFileCommonHelper::getOnlyFileName(whiteImgFullPath);
                string suffName = CFileCommonHelper::getFileNoName(whiteImgFullPath);

                // 提取特征值后移动文件到备份
                string bakFile = copyAfterFileName+ "_" + timeTick + "." + suffName;
                string bakFullFile = bakFile;
                std::cout << "bakFullFile = " << bakFullFile<<std::endl;
                BOOL bMove = MoveFileA(whiteImgFullPath.c_str(),bakFullFile.c_str());
                info.name = vecFile[0];
                info.cell = vecFile[1];
                info.group = vecFile[2];
                info.jobs = vecFile[3];
                info.tick = timeTick;
                info.tempImg = bakFullFile;
                memcpy(info.fea,szFea,8192);
                std::cout << "addLists white" <<std::endl;
                CSqliteWhite::signle()->addLists(info);
                _writeLists.push_back(info);
            }

        }
        string timeTick1 = CDateTimeHelper::getDateTimeString(0);
        string orgTxt = writeImg + "whiteList.txt";
        string bakTxt = writeBak+"whiteList_"+timeTick1+".txt";
        MoveFileA(orgTxt.c_str(),bakTxt.c_str());
    }

    return bExist;
}
