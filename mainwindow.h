#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
//#include <QMediaPlayer>
#include <QLabel>
#include <mutex>
#include <QTimer>
#include <QWebEngineView>

#include "FileCommonHelper.h"
#include "opencv2/opencv.hpp"
#include "alg_face_detect.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QPoint pLast;
    bool m_bPressed;
    QPoint clickPos;
    bool m_bresize=false;
    std::mutex _mutexFace;
    bool _bHaveFace;
    int  _nFaceNum;
    RECT* _rcFace;

    bool    _bDealDetectFace;
    string  _todayImgPath;

    QTimer *_timer;

    bool  _bPlate;
    QWebEngineView *_view;
private:
    void initVideoUI();
    void initPath();
    void initUI();
protected:
    void mouseMoveEvent(QMouseEvent * event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent * event);
    void LabelDisplayMat(QLabel *label, cv::Mat &mat);
protected slots:
    void onCaptureImg(cv::Mat img);
    void onCaptureImgMsg(cv::Mat img);
    void onFaceDetect(RECT* rc,int nFace);
    void onCompareFace(bool bSuccess,SFaceFeatureInfo info,cv::Mat mat,int nCoat,int nHelmet);
private slots:
    void on_btnSetting_clicked();
    void on_btnPlate_clicked();
    void on_btnRecord_clicked();
    void slotTimerUpdate();
    void onHelmetUiTip(int bPlay);
    signals:
    void stopDetect(bool bStop);
    void stopSend(bool bStop);
    void playsoundSignal(int bPlay);
};
#endif // MAINWINDOW_H
