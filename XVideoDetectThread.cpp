#include "XVideoDetectThread.h"
#include <iostream>
#include <QDebug>
using namespace std;
static cv::VideoCapture g_cap2;
XVideoDetectThread::XVideoDetectThread()
    : _bInited(false)
{
    start();
}


XVideoDetectThread::~XVideoDetectThread()
{
}

bool XVideoDetectThread::Open(int n)
{
    m_mutex.lock();
    bool nRe = g_cap2.open(n);
    g_cap2.open(0);
    m_mutex.unlock();
    if(nRe)
    {
        _bInited = true;
    }
    return nRe;
}




void XVideoDetectThread::run()
{
    cv::Mat mat1;
    std::cout << "run() into while" <<std::endl;
    while (true) {
        if(!_bInited)
        {
            msleep(100);
            continue;
        }
        m_mutex.lock();
        if (!g_cap2.isOpened()) {
            qDebug() << "cap img no open";
            m_mutex.unlock();
            msleep(5);
            continue;
        }
        g_cap2 >> mat1;
//        flip(mat1, mat1, 1);
        m_mutex.unlock();
        ViewImageDetect(mat1);
    }
}
