#ifndef XFACEDETECTTHREAD_H
#define XFACEDETECTTHREAD_H
//#pragma execution_character_set("utf-8")
#include <QThread>
#include <mutex>
#include "opencv2/opencv.hpp"
#include "alg_face_detect.h"
#include "FileCommonHelper.h"


class XFaceDetectThread : public QThread
{
    Q_OBJECT

protected:
    XFaceDetectThread();
    bool            _bInited;
    std::mutex      _mutexImg;
    cv::Mat         _mat;

    std::vector<SFaceFeatureInfo>   _writeLists;
    bool            _pauseDetect;       //暂停比对
    bool            _pauseSendDetect;
private:
    bool GetFea(cv::Mat img, unsigned char szFea[8192]);
    bool GetFea(std::string strName, unsigned char szFea[8192]);
    bool GetFea(cv::Mat img,FacePointInfo faceInfo[1024],unsigned char* szFea[8192],int nFace);
    void loadFea();

    bool getFeaFromFile(std::string fileName,SFaceFeatureInfo& info);
    // 提取白名单
    bool onCheckWhiteListsFile();

    std::vector<string> readTxt(string fileName);
public:
    static XFaceDetectThread* signle()
    {
        static XFaceDetectThread s;
        return &s;
    }

    virtual void run();

    public slots:
    void onInited(int nInit);
    void onCaptureImg(cv::Mat mat);
    void onDetectStop(bool bStop);
    void onSendStop(bool bStop);
signals:
    void detectFaceRect(RECT* rc,int nFace);
    void compareFace(bool bSuccess,SFaceFeatureInfo info,cv::Mat mat,int nCoat,int nHelmet);
};

#endif // XFACEDETECTTHREAD_H
