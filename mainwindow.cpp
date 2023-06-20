#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMessageBox>
#include <QThread>
#include <QDialog>
#include <QDateTime>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QTextCodec>
#include <QLineEdit>
#include <QWebEngineView>
#include <QTableWidget>
#include <QTextToSpeech>
#include <QDesktopServices>
#include <QHeaderView.h>
#include "sqlite_record.h"
#include "DateTimeHelper.h"
#include "sqlite3.h"
#include "XVideoThread.h"
#include "XVideoDetectThread.h"
#include "XFaceDetectThread.h"
#include "opencv2/opencv.hpp"
#include "xinitthread.h"
#include "sqlite_white.h"
#include "config_file.h"
#include "MyPlaySoundThread.h"
#include "chelmettip.h"
#include "PageControl.h"
using namespace cv;


void MainWindow::initVideoUI()
{
    qRegisterMetaType<cv::Mat>("cv::Mat");
    qRegisterMetaType<RECT*>("RECT*");
    qRegisterMetaType<SFaceFeatureInfo>("SFaceFeatureInfo");

    XInitThread* initThread = new XInitThread();
    connect(initThread,&XInitThread::initSignal,XFaceDetectThread::signle(),&XFaceDetectThread::onInited);

    initThread->start();
    connect(XVedioThread::Signle(), &XVedioThread::ViewImage1, this,
            &MainWindow::onCaptureImgMsg);
    bool bRet = XVedioThread::Signle()->Open("./resource/123.mp4");
        if (!bRet) {
            QMessageBox::information(this, "error", QString::fromLocal8Bit("打开失败"));
        }

    connect(XVideoDetectThread::Signle(), &XVideoDetectThread::ViewImageDetect,this,
                &MainWindow::onCaptureImg);

    connect(this,&MainWindow::stopDetect,XFaceDetectThread::signle(),&XFaceDetectThread::onDetectStop);
    connect(this,&MainWindow::stopSend,XFaceDetectThread::signle(),&XFaceDetectThread::onSendStop);
    connect(XVideoDetectThread::Signle(), &XVideoDetectThread::ViewImageDetect,XFaceDetectThread::signle(),
                &XFaceDetectThread::onCaptureImg);
    connect(XFaceDetectThread::signle(),&XFaceDetectThread::detectFaceRect,this,&MainWindow::onFaceDetect);
    connect(XFaceDetectThread::signle(),&XFaceDetectThread::compareFace,this,&MainWindow::onCompareFace);
    XFaceDetectThread::signle()->start();
    //当timer的timeout()信号发出后，触发slotTimerUpdate()槽函数
    connect(_timer,SIGNAL(timeout()),this,SLOT(slotTimerUpdate()));
    connect(this,&MainWindow::playsoundSignal,this,&MainWindow::onHelmetUiTip);
    connect(this,&MainWindow::playsoundSignal,CMyPlaySoundThread::signle(),&CMyPlaySoundThread::onPlaySoundHandle);
    _timer->start(1000);
    CMyPlaySoundThread::signle()->start();
}

void MainWindow::onHelmetUiTip(int bPlay)
{
    if(bPlay == -1)
    {
        return;
    }
    QString str = "进出人员请佩戴安全帽";
    if(bPlay == 1)
    {
        str = "进出人员请穿反光衣";
    }else if(bPlay == 2)
    {
        str = "进出人员请佩戴安全帽及穿反光衣";
    }

    CHelmetTip * p_widget = new CHelmetTip(str,this);
    int x, y;
    x = 30;
    y = 125;
    //设置控件显示的位置
    p_widget->setGeometry(x,y, 1020,144);
    p_widget->show();
}
void MainWindow::onFaceDetect(RECT* rc,int nFace)
{
    _mutexFace.lock();
    _bHaveFace = true;
    _nFaceNum = nFace;
    for(int i = 0;i<nFace;++i)
    {
        _rcFace[i].bottom = rc[i].bottom ;
        _rcFace[i].top = rc[i].top ;
        _rcFace[i].left = rc[i].left ;
        _rcFace[i].right = rc[i].right ;
    }

    _mutexFace.unlock();
}
//参数1-显示图像的Label，参数2-要显示的Mat
void MainWindow::LabelDisplayMat(QLabel *label, cv::Mat &mat)
{
    cv::Mat Rgb;
    QImage Img;
    if (mat.channels() == 3)//RGB Img
    {
        cv::cvtColor(mat, Rgb, cv::COLOR_BGR2RGB);//颜色空间转换
        Img = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
    }
    else//Gray Img
    {
        Img = QImage((const uchar*)(mat.data), mat.cols, mat.rows, mat.cols*mat.channels(), QImage::Format_Indexed8);
    }
    label->setPixmap(QPixmap::fromImage(Img));
}

void MainWindow::onCompareFace(bool bSuccess,SFaceFeatureInfo info,cv::Mat mat,int nCoat,int nHelmet)
{
    cv::Mat matCopy;mat.copyTo(matCopy);
    cv::Mat matUseing;mat.copyTo(matUseing);
    string stamp = CDateTimeHelper::getDateTimeString(0);
    int nSoundSignle = -1;
    if(nHelmet == 2 )
    {
        nSoundSignle = 0;
    }
    if(nCoat == 2 )
    {
        nSoundSignle = 1;
    }
    if(nCoat == 2 && nHelmet == 2 )
    {
        nSoundSignle = 2;
    }
    string strLog = "nHelmet = " + to_string(nHelmet) +",nCoat = " + to_string(nCoat) +",nSoundSignle = " + to_string(nSoundSignle);
    CDateTimeHelper::writeSimpleLog(strLog);
    std::cout <<"nHelmet = " << nHelmet <<",nCoat = " << nCoat <<",nSoundSignle = " << nSoundSignle<<std::endl;
    emit playsoundSignal(nSoundSignle);


    if(!bSuccess)
    {
        QString strNumMo = ui->labMo->text();
        int nNumNo = strNumMo.toInt();
        nNumNo++;
        ui->labMo->setText(to_string(nNumNo).c_str());
        QString strNumToTal = ui->labTotal->text();
        int nNumToTal = strNumToTal.toInt();
        nNumToTal++;
        ui->labTotal->setText(to_string(nNumToTal).c_str());
        if(nCoat == 1)
        {
            ui->labCoat->setText("有");
        }else
        {
            ui->labCoat->setText("无");
        }
        if(nHelmet == 1)
        {
            ui->labHelmet->setText("有");
        }else
        {
            ui->labHelmet->setText("无");
        }
        string name = "姓名：未知" ;
        string comp = "公司：未知" ;
        string group = "班组：未知";
        string jobs = "工种：未知" ;

        ui->labName->setText(name.c_str()) ;
        ui->labCompany->setText(comp.c_str()) ;
        ui->labGroup->setText(group.c_str()) ;
        ui->labGongZ->setText(jobs.c_str());

        cv::resize(matCopy, matCopy, Size(ui->labTemp->size().width(), ui->labTemp->size().height()));
        LabelDisplayMat(ui->labTemp,matCopy);
        //保存记录
        SRecordInfo info;
        info.coat = nCoat;
        info.helmet = nHelmet;
        info.name = "";info.groupName = "";info.jobs = "";info.white = 0;info.stamp =stamp;
        string imgName = _todayImgPath + stamp + ".jpg";cv::imwrite(imgName.c_str(),matUseing);
        info.realImg = imgName;

        CSqliteRecord::signle()->addRecord(info);
        std::cout <<"add record finish " <<std::endl;
        return;
    }

    string imgFile = info.tempImg;
    string name = "姓名：" + info.name;
    string comp = "公司：" + info.cell;
    string group = "班组：" +info.group;
    string jobs = "工种：" + info.jobs;
    cv::Mat img = cv::imread(imgFile);

    cv::resize(img, img, Size(ui->labTemp->size().width(), ui->labTemp->size().height()));
    LabelDisplayMat(ui->labTemp,img);
    ui->labName->setText(name.c_str()) ;
    ui->labCompany->setText(comp.c_str()) ;
    ui->labGroup->setText(group.c_str()) ;
    ui->labGongZ->setText(jobs.c_str());
    if(nCoat == 1)
    {
        ui->labCoat->setText("有");
    }else
    {
        ui->labCoat->setText("无");
    }
    if(nHelmet == 1)
    {
        ui->labHelmet->setText("有");
    }else
    {
        ui->labHelmet->setText("无");
    }
    QString strNumMo = ui->labSuccess->text();
    int nNumNo = strNumMo.toInt();
    nNumNo++;
    ui->labSuccess->setText(to_string(nNumNo).c_str());
    QString strNumToTal = ui->labTotal->text();
    int nNumToTal = strNumToTal.toInt();
    nNumToTal++;
    ui->labTotal->setText(to_string(nNumToTal).c_str());
    SRecordInfo recInfo;
    recInfo.coat = nCoat;
    recInfo.helmet = nHelmet;
    recInfo.name = info.name;recInfo.groupName = info.group;recInfo.jobs = info.jobs;recInfo.white = 1;recInfo.stamp =stamp;
    string imgName = _todayImgPath + stamp + ".jpg";cv::imwrite(imgName.c_str(),mat);
    recInfo.realImg = imgName;
    CSqliteRecord::signle()->addRecord(recInfo);
    std::cout <<"add white record finish" <<std::endl;
    return;
}

void MainWindow::onCaptureImgMsg(cv::Mat img)
{
    Mat des;
    cv::resize(img, des, Size(ui->label_5->size().width(), ui->label_5->size().height()));
    LabelDisplayMat(ui->label_5,des);
}

void MainWindow::onCaptureImg(cv::Mat img)
{
    Mat des;
    if(_bHaveFace)
    {
        cv::Rect rc;
        _mutexFace.lock();
        _bHaveFace = false;
        for(int i = 0;i<_nFaceNum;++i)
        {
            rc.x = _rcFace[i].left;
            rc.y = _rcFace[i].top;
            rc.width = _rcFace[i].right - _rcFace[i].left;
            rc.height = _rcFace[i].bottom - _rcFace[i].top;
            cv::rectangle(img,rc,(255,128,255),2);
        }
        _nFaceNum =0;
        _mutexFace.unlock();
    }
    cv::resize(img, des, Size(ui->label->size().width(), ui->label->size().height()));
    LabelDisplayMat(ui->label,des);
}

void MainWindow::initPath()
{
    string currPath = CFileCommonHelper::getCurrentPath();
    string resourcePath = currPath + "\\resource\\";
    if(!CFileCommonHelper::pathExist(resourcePath))
    {
        CFileCommonHelper::createDir(resourcePath);
    }
    string recordPath = resourcePath + "record\\";
    if(!CFileCommonHelper::pathExist(recordPath))
    {
        qDebug()<< "create recordPath = " << recordPath.c_str();
        CFileCommonHelper::createDir(recordPath);
    }

    string today = CDateTimeHelper::getDateTimeString(2);
    string todayPath = recordPath + today + "\\";
    if(!CFileCommonHelper::pathExist(todayPath))
    {
        qDebug()<< "create today img path = " << todayPath.c_str();
        CFileCommonHelper::createDir(todayPath);
    }
    _todayImgPath = todayPath;

    string whitePath = resourcePath + "white\\";
    if(!CFileCommonHelper::pathExist(whitePath))
    {
        qDebug()<< "create whitePath = " << whitePath.c_str();
        CFileCommonHelper::createDir(whitePath);
    }

    string whiteImgPath = resourcePath + "whiteImg\\";
    if(!CFileCommonHelper::pathExist(whiteImgPath))
    {
        CFileCommonHelper::createDir(whiteImgPath);
    }

    string whiteImgPathBak = resourcePath + "whiteImgBak\\";
    if(!CFileCommonHelper::pathExist(whiteImgPathBak))
    {
        CFileCommonHelper::createDir(whiteImgPathBak);
    }

}


void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() && Qt::LeftButton&&m_bPressed)
    {
        move(event->globalPos() - pLast);
        event->accept();
    }

    if (isMaximized())
    {
        return;
    }

    int iWidth=this->width();
    int iHeight=this->height();

    if(event->pos().x()>iWidth-10&&event->pos().y()>iHeight-10)
    {
         this->setCursor(Qt::SizeFDiagCursor);
         int width=this->width()-(this->width()-event->pos().x());
         int height=this->height()- (this->height()-event->pos().y());
         if(m_bresize==true)
         {
             this->resize(width,height);
         }

    }
    else
    {
        this->setCursor(Qt::ArrowCursor);
    }
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int width=this->width();
    int height=this->height();

    if(event->pos().x()>width-10&&event->pos().y()>height-10&&event->buttons() == Qt::LeftButton)
    {
        clickPos=event->pos();
        m_bresize=true;
    }
    else
    {
        m_bPressed = true;
        pLast = event->globalPos() - this->pos();
        event->accept();
    }

}

void MainWindow::mouseReleaseEvent(QMouseEvent *event)
{
     m_bPressed = false;
     m_bresize=false;
}

//获取当前时间
void MainWindow::slotTimerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();//获取当前日期和时间
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");//格式为年-月-日 小时-分钟-秒 星期
    ui->labTime->setText(str);
}

void MainWindow::initUI()
{
    string title = CConfig::signle()->getTitle();
    string proName = CConfig::signle()->getProName();
    string company = CConfig::signle()->getCompany();

    ui->label_2->setText(company.c_str());
    ui->label_3->setText(title.c_str());
    ui->label_4->setText(proName.c_str());
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , _bDealDetectFace(false)
    , _rcFace(new RECT[1024])
    , _nFaceNum(0)
    , _bPlate(false)
{
    ui->setupUi(this);
    _timer = new QTimer(this);

    #if (QT_VERSION <= QT_VERSION_CHECK(5,0,0))
    #if _MSC_VER
    QTextCodec *codec = QTextCodec::codecForName("GBK");
    #else
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    #endif
    QTextCodec::setCodecForLocale(codec);
    QTextCodec::setCodecForCStrings(codec);
    QTextCodec::setCodecForTr(codec);
    #else
    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);
    #endif
    _view = new QWebEngineView(ui->widget_5);
    _view->setGeometry(0 ,75 ,1025, 503);
    _view->lower();

    CConfig::signle()->initConfig();
    setWindowFlags(Qt::FramelessWindowHint | windowFlags());
    setCentralWidget(ui->widget);
    initUI();
    bool bRet = CSqliteRecord::signle()->openRecordDb();
    if(bRet)
    {
        std::cout <<"open record db ok"<<std::endl;
    }else{
        std::cout <<"open record db failed"<<std::endl;
    }
    initPath();
    initVideoUI();
}

MainWindow::~MainWindow()
{
}

void MainWindow::on_btnSetting_clicked()
{
    QDialog dialog(this);
    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);
    dialog.setWindowTitle("设置页面");
    dialog.setStyleSheet("color:#ff6600;");
    QFormLayout form(&dialog);
    form.addRow(new QLabel("用户设置:"));
    // Value1
    int nScore = CConfig::signle()->getScore();
    QLineEdit* e1 = new QLineEdit(to_string(nScore).c_str(),&dialog);
    form.addRow(QString("人脸比对分值:"), e1);
    string url = CConfig::signle()->getUrl();
    QLineEdit* e2 = new QLineEdit(url.c_str(),&dialog);
    form.addRow(QString("平台地址:"), e2);

    string title = CConfig::signle()->getTitle();
    std::cout << "title = " << title<<std::endl;
//    title = CFileCommonHelper::UTF8ToString(title);
//    QString qTitle = codec->toUnicode();

    QLineEdit* e3 = new QLineEdit(title.c_str(),&dialog);
    form.addRow(QString("标题:"), e3);

    string proName = CConfig::signle()->getProName();

    QLineEdit* e4 = new QLineEdit(proName.c_str(),&dialog);
    form.addRow(QString("项目名称:"), e4);

    string strCompany = CConfig::signle()->getCompany();
    QLineEdit* e5 = new QLineEdit(strCompany.c_str(),&dialog);
    form.addRow(QString("公司名:"),e5);

    // Add Cancel and OK button
    QDialogButtonBox buttonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        Qt::Horizontal, &dialog);
    form.addRow(&buttonBox);
    QObject::connect(&buttonBox, SIGNAL(accepted()), &dialog, SLOT(accept()));
    QObject::connect(&buttonBox, SIGNAL(rejected()), &dialog, SLOT(reject()));

    // Process when OK button is clicked
    if (dialog.exec() == QDialog::Accepted) {
        // Do something here
        QString strScore = e1->text(); int nS = strScore.toInt();CConfig::signle()->setScore(nS);
        QString strUrl = e2->text();CConfig::signle()->setUrl(strUrl.toStdString());
        QString strTitle = e3->text(); CConfig::signle()->setTitle(strTitle.toStdString());
        QString strProName = e4->text(); CConfig::signle()->setProName(strProName.toStdString());
        QString strCom = e5->text();CConfig::signle()->setCompany(strCom.toStdString());

        initUI();
    }
}

void MainWindow::on_btnPlate_clicked()
{
    if(!_bPlate)
    {
        ui->btnPlate->setText("设备");
        string url = CConfig::signle()->getUrl();

        _view->load(QUrl(url.c_str()));
        _view->raise();
        _view->show();
        _bPlate = true;
    }else{
        ui->btnPlate->setText("平台");
        ui->label_5->raise();
        _bPlate = false;
    }
}

void MainWindow::on_btnRecord_clicked()
{
    //发送停止比对信号
    bool bStop = true;
    emit stopDetect(bStop);
    bStop = false;


    QDialog dialog(this);
    dialog.setWindowTitle("本月比对记录");
    dialog.resize(1080,1920);
    dialog.move(0,0);
    PageControl pc(&dialog);
    pc.move(0,1830);
    pc.resize(800,80);

    QTextCodec *codec = QTextCodec::codecForName("UTF-8");
    QTextCodec::setCodecForLocale(codec);

//    dialog.setStyleSheet("background-color: rgb(88, 96, 101);");
    QTableWidget table(&dialog);
    QString styleStr = "QTableWidget { alternate-background-color: white; font-size: 14pt; }";
    styleStr.append(" QTableWidget::item:selected { color:#FFFFFF;background: #4B4B4D; };");
    styleStr.append("QTableWidget::item {text-align: center;color:rgba(255,255,255,150);background: #303033;};");
    styleStr.append("QTableWidget::item::hovercolor:#FFFFFF;background: #4B4B4D;");

    table.horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    table.setStyleSheet(styleStr);
    table.move(0,0);
    table.setSelectionBehavior(QAbstractItemView::SelectRows); //设置选择行为时每次选择一行
    table.setEditTriggers(QAbstractItemView::NoEditTriggers); //设置不可编辑
    table.horizontalHeader()->setDefaultAlignment(Qt::AlignHCenter);

    table.setAlternatingRowColors(true);
    table.verticalHeader()->setDefaultSectionSize(200);

    table.resize(1080,1820);
    table.move(0,0);
    table.setSelectionBehavior(QAbstractItemView::SelectRows);//设置整行选中
    table.setColumnCount(6);
    table.setColumnWidth(5, 140);
    QStringList header;  //QString类型的List容器
    header<<"姓名"<<"工种"<<"是否佩戴安全帽"<<"是否穿着反光衣"<<"通过时间"<<"现场图片";//设置内容是学号、姓名、性别
    table.setHorizontalHeaderLabels(header);//设置表头内容
    vector<SRecordInfo> recordInfos;
    CSqliteRecord::signle()->loadRecordLists(recordInfos);
    std::reverse(recordInfos.begin(),recordInfos.end());
//    std::sort(recordInfos.rbegin(),recordInfos.rend());
    std::cout <<"recordInfos size = " << recordInfos.size()<<std::endl;
    int total = recordInfos.size();
    pc.initPage(total);
    pc.setTotal(total);
    int nPageSize = 10;

    //让tableWidget内容中的每个元素居中
    connect(&pc,&PageControl::pageChanged,this,[&table,nPageSize,total,recordInfos](int currentPage){
        std::cout <<"currentPage = " << currentPage<<std::endl;
        int nStart = (currentPage - 1) * nPageSize;
        int nEnd = currentPage * nPageSize;if(nEnd > total){nEnd = total;}
        std::cout <<"start = " << nStart <<",nEnd = " << nEnd<<std::endl;
        // 清空表格并重新设置行列数
        table.clearContents();
        table.setRowCount(0);

        for(int i = nStart;i< nEnd;++i)
        {
            int RowCont;
            RowCont=table.rowCount();
            table.insertRow(RowCont);//增加一行

            //插入元素
            table.setItem(RowCont,0,new QTableWidgetItem(recordInfos[i].name.c_str()));
            table.item(RowCont, 0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            table.setItem(RowCont,1,new QTableWidgetItem(recordInfos[i].jobs.c_str()));
            table.item(RowCont, 1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            table.setItem(RowCont,2,new QTableWidgetItem(recordInfos[i].helmet == 1?"是":"否"));
            table.item(RowCont, 2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            table.setItem(RowCont,3,new QTableWidgetItem(recordInfos[i].coat == 1?"是":"否"));
            table.item(RowCont, 3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            table.setItem(RowCont,4,new QTableWidgetItem(recordInfos[i].stamp.c_str()));
            table.item(RowCont, 4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

            QLabel *label = new QLabel("");
            cv::Mat mat = cv::imread(recordInfos[i].realImg.c_str());
            cv::resize(mat,mat,cv::Size(140,200));
            cv::Mat Rgb;
            QImage Img;
            if (mat.channels() == 3)//RGB Img
            {
                cv::cvtColor(mat, Rgb, cv::COLOR_BGR2RGB);//颜色空间转换
                Img = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
            }
            else//Gray Img
            {
                Img = QImage((const uchar*)(mat.data), mat.cols, mat.rows, mat.cols*mat.channels(), QImage::Format_Indexed8);
            }
            label->setPixmap(QPixmap::fromImage(Img));

//            LabelDisplayMat(label,img);
//            label->setPixmap(QPixmap(recordInfos[i].realImg.c_str()).scaled(140,200));
            label->setAlignment(Qt::AlignHCenter);
            table.setCellWidget(RowCont,5,label);

        }


    });


    int nInitNum = recordInfos.size() > nPageSize?nPageSize:recordInfos.size();
    std::cout <<"nInitNum = " << nInitNum<<std::endl;
    for(int i = 0;i< nInitNum;++i)
    {
        int RowCont;
        RowCont=table.rowCount();
        table.insertRow(RowCont);//增加一行

        //插入元素
        table.setItem(RowCont,0,new QTableWidgetItem(recordInfos[i].name.c_str()));
        table.item(RowCont, 0)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        table.setItem(RowCont,1,new QTableWidgetItem(recordInfos[i].jobs.c_str()));
        table.item(RowCont, 1)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        table.setItem(RowCont,2,new QTableWidgetItem(recordInfos[i].helmet == 1?"是":"否"));
        table.item(RowCont, 2)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        table.setItem(RowCont,3,new QTableWidgetItem(recordInfos[i].coat == 1?"是":"否"));
        table.item(RowCont, 3)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
        table.setItem(RowCont,4,new QTableWidgetItem(recordInfos[i].stamp.c_str()));
        table.item(RowCont, 4)->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);

        QLabel *label = new QLabel("");
        CDateTimeHelper::writeSimpleLog(recordInfos[i].realImg);

        cv::Mat mat = cv::imread(recordInfos[i].realImg.c_str());
        cv::resize(mat,mat,cv::Size(140,200));
        cv::Mat Rgb;
        QImage Img;
        if (mat.channels() == 3)//RGB Img
        {
            cv::cvtColor(mat, Rgb, cv::COLOR_BGR2RGB);//颜色空间转换
            Img = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
        }
        else//Gray Img
        {
            Img = QImage((const uchar*)(mat.data), mat.cols, mat.rows, mat.cols*mat.channels(), QImage::Format_Indexed8);
        }
        label->setPixmap(QPixmap::fromImage(Img));

//        label->setPixmap(QPixmap(recordInfos[i].realImg.c_str()).scaled(140,200));
        label->setAlignment(Qt::AlignHCenter);
        table.setCellWidget(RowCont,5,label);

    }

    dialog.exec();
    emit stopDetect(bStop);
}
