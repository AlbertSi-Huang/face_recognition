#include "xinitthread.h"
#include "alg_face_detect.h"
#include "XVideoDetectThread.h"
#include <QDebug>
#include "FileCommonHelper.h"
#include "alg_coat_detect.h"
#include "alg_helmet_detect.h"
#include <vector>

using namespace std;

XInitThread::XInitThread()
{
//    start();
}

void XInitThread::loadWriteList()
{
    string currPath = CFileCommonHelper::getCurrentPath();
    string writePath = currPath+"\\resource\\write\\";
    std::vector<std::string> wrietFullListFiles;
    std::vector<std::string> wrietListFiles;
    CFileCommonHelper::getFileNames(writePath,wrietFullListFiles,wrietListFiles);

}

void XInitThread::run()
{
    bool bFaceInit =false;
    bFaceInit = CAlgFaceDetect::signle().init();
    if(!bFaceInit)
    {
        emit initSignal(1);
        return;
    }
//    qDebug() << "face detect init success";
    bFaceInit = XVideoDetectThread::Signle()->Open();
    if(!bFaceInit)
    {
        emit initSignal(2);
        return;
    }

    bool bCoatInit = CAlgCoatDetct::signle().init();
    if(!bCoatInit)
    {
        emit initSignal(3);
        return;
    }

    bool bHelmetInit = CAlgHelmetDetect::signle().init();
    if(!bHelmetInit)
    {
        emit initSignal(4);
        return;
    }

    emit initSignal(0);
}
