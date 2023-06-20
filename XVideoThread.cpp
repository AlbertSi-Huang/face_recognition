#include "XVideoThread.h"
#include <iostream>

using namespace std;

static cv::VideoCapture g_cap1;

XVedioThread::XVedioThread()
: m_isexit(false)
, m_fps (0)
, _fcount(0)
{
    start();
}


XVedioThread::~XVedioThread()
{
    m_mutex.lock();
    m_isexit = true;
    m_mutex.unlock();
}

bool XVedioThread::Open(const std::string fileName)
{
    m_mutex.lock();
    bool nRe = g_cap1.open(fileName.c_str());
    m_mutex.unlock();
    cout << "re = " << nRe << endl;
    if (nRe) {
        m_fps = g_cap1.get(cv::CAP_PROP_FPS);
        if (m_fps <= 0) {
            m_fps = 25;
        }
    }
    _fcount = g_cap1.get(cv::CAP_PROP_FRAME_COUNT);
    std::cout <<"_fcount = " << _fcount <<std::endl;
    return nRe;
}

double XVedioThread::GetPos() {
    double pos = 0;
    m_mutex.lock();
    if (!g_cap1.isOpened()) {
        m_mutex.unlock();
        return pos;
    }
    double nCount = g_cap1.get(cv::CAP_PROP_FRAME_COUNT);
    double nCur = g_cap1.get(cv::CAP_PROP_POS_FRAMES);
    if (nCount > 0.0001)
        pos = nCur / nCount;
    m_mutex.unlock();

    return pos;
}

void XVedioThread::run()
{
    cv::Mat mat1;
    while (true) {
        m_mutex.lock();

        if (m_isexit) {
            m_mutex.unlock(); break;
        }
        if (!g_cap1.isOpened()) {
            m_mutex.unlock();
            msleep(5);
            continue;
        }
        int cur = g_cap1.get(cv::CAP_PROP_POS_FRAMES); // 当前帧
//        std::cout <<"cur = " << cur<<std::endl;
//        // 当前帧索引大于（fcount - 1），则重新播放。
        if (cur > (_fcount - 1) ) {
            g_cap1.set(cv::CAP_PROP_POS_FRAMES, 0); // 设置当前帧为0，循环播放。
            m_mutex.unlock();
            continue;
        }

        if ((!g_cap1.read(mat1)) || mat1.empty()) {
            m_mutex.unlock();
            msleep(5);
            continue;
        }

        ViewImage1(mat1);
        msleep(1000 / m_fps);
        m_mutex.unlock();
    }
}

bool XVedioThread::Seek(double nPos) {
    m_mutex.lock();
    double nCount = g_cap1.get(cv::CAP_PROP_FRAME_COUNT);
    m_mutex.unlock();
    int frame = nPos * nCount;
    return Seek(frame);
}


bool XVedioThread::Seek(int frame)
{
    m_mutex.lock();
    bool nRet = g_cap1.set(cv::CAP_PROP_POS_FRAMES, frame);
    m_mutex.unlock();

    return nRet;
}


