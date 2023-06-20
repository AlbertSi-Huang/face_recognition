#ifndef QXVIDEODETECTWIDGET_H
#define QXVIDEODETECTWIDGET_H
#include <QLabel>
#include <QImage>
#include <QPaintEvent>
#include "opencv2/opencv.hpp"

class QXVideoDetectWidget : public QLabel
{
    Q_OBJECT
public:
    QXVideoDetectWidget(QWidget* p);
    virtual ~QXVideoDetectWidget();

public slots:
    void SetImageDetect(cv::Mat mat);

private:
    QImage cvMat2QImage(const cv::Mat& mat);
    void paintEvent(QPaintEvent * e);
private:
    QImage m_img;
};

#endif // QXVIDEODETECTWIDGET_H
