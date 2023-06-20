#ifndef XVIDEOTHREAD_H
#define XVIDEOTHREAD_H
#include <QThread>
#include <QMutex>
#include "opencv2/opencv.hpp"

class XVedioThread : public QThread
{
    Q_OBJECT

public:
    static XVedioThread* Signle() {
        static XVedioThread xv;
        return &xv;
    }

    virtual ~XVedioThread();
    bool Open(const std::string fileName);

    void run();
    int GetFps() { return m_fps; }
    //跳转视频
    bool Seek(int frame);
    bool Seek(double nPos);

    double GetPos();	//
signals:
    void ViewImage1(cv::Mat mat);
protected:
    XVedioThread();
    QMutex m_mutex;

    bool m_isexit;
    int	 m_fps;
    int _fcount;
};
#endif // XVIDEOTHREAD_H
