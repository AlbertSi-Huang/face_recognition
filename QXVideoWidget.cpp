#include "QXVideoWidget.h"
#include <QPainter>
#include <QDebug>
using namespace cv;

QImage QXVideoWidget::cvMat2QImage(const cv::Mat& mat)
{
    // 8-bits unsigned, NO. OF CHANNELS = 1
    if(mat.type() == CV_8UC1)
    {
        QImage image(mat.cols, mat.rows, QImage::Format_Indexed8);
        for(int i = 0; i < 256; i++)
        {
            image.setColor(i, qRgb(i, i, i));
        }
        // Copy input Mat
        uchar *pSrc = mat.data;
        for(int row = 0; row < mat.rows; row ++)
        {
            uchar *pDest = image.scanLine(row);
            memcpy(pDest, pSrc, mat.cols);
            pSrc += mat.step;
        }
        return image;
    }
    // 8-bits unsigned, NO. OF CHANNELS = 3
    else if(mat.type() == CV_8UC3)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_RGB888);
        return image.rgbSwapped();
    }
    else if(mat.type() == CV_8UC4)
    {
        // Copy input Mat
        const uchar *pSrc = (const uchar*)mat.data;
        // Create QImage with same dimensions as input Mat
        QImage image(pSrc, mat.cols, mat.rows, mat.step, QImage::Format_ARGB32);
        return image.copy();
    }
    else
    {
        return QImage();
    }
}


void QXVideoWidget::SetImage(Mat mat) {
    if (m_img.isNull()) {
        uchar* buf = new uchar[width() * height() * 3];
        m_img = QImage(buf, width(), height(), QImage::Format_RGB30);
    }
    Mat des;
    cv::resize(mat, des, Size(m_img.size().width(), m_img.size().height()));
    m_img = cvMat2QImage(des);
//    cv::imshow("des",des);
    update();
}



QXVideoWidget::QXVideoWidget(QWidget* p)
    :QOpenGLWidget(p)
{
}

void QXVideoWidget::paintEvent(QPaintEvent * e)
{
    QPainter p;
    p.begin(this);
    p.drawImage(QPoint(0,0), m_img);
    p.end();
}


QXVideoWidget::~QXVideoWidget()
{
}





