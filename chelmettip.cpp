#include "chelmettip.h"
#include "ui_chelmettip.h"
#include <QTimer>

CHelmetTip::CHelmetTip(QString str,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CHelmetTip)
{
    ui->setupUi(this);
    this->setWindowFlags(Qt::FramelessWindowHint
          | Qt::Tool
          | Qt::WindowStaysOnTopHint);
        //设置属性：关闭即销毁
        this->setAttribute(Qt::WA_DeleteOnClose);
        //text为要显示的信息
        ui->label->setText(str);
        //设置定时器，到时关闭弹框
        QTimer* timer = new QTimer(this);
        timer->start(2000);//时间1.5秒
        timer->setSingleShot(true);//仅触发一次
        connect(timer, SIGNAL(timeout()), this, SLOT(onTimeupDestroy()));
}

 void CHelmetTip::onTimeupDestroy()
 {
    this->close();
 }

CHelmetTip::~CHelmetTip()
{
    delete ui;
}
