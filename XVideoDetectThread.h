#ifndef XVIDEODETECTTHREAD_H
#define XVIDEODETECTTHREAD_H
#include <QThread>
#include <QMutex>
#include "opencv2/opencv.hpp"

class XVideoDetectThread : public QThread
{
    Q_OBJECT

public:
    static XVideoDetectThread* Signle() {
        static XVideoDetectThread xv;
        return &xv;
    }

    virtual ~XVideoDetectThread();
    bool Open(int n = 0);
    void run();


signals:
    void ViewImageDetect(cv::Mat mat);

protected:
    XVideoDetectThread();
    QMutex m_mutex;

    bool _bInited;
    bool _bDetectStop;
private:
    QImage cvMat2QImage(const cv::Mat& mat);
};

#endif // XVIDEODETECTTHREAD_H
