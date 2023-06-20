#ifndef QXVIDEOWIDGET_H
#define QXVIDEOWIDGET_H
#include <qopenglwidget.h>
#include "opencv2/opencv.hpp"
#include <QImage>

class QXVideoWidget : public QOpenGLWidget
{
    Q_OBJECT

public:
    QXVideoWidget(QWidget* p);
    void paintEvent(QPaintEvent* e);
    virtual ~QXVideoWidget();

public slots:
    void SetImage(cv::Mat mat);

    protected:
        //自己重新实现拖动操作
    QImage cvMat2QImage(const cv::Mat& mat);

private:
    QImage m_img;
    cv::Mat m_imgDetect;
};


#endif // QXVIDEOWIDGET_H
