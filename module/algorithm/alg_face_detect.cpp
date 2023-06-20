#include "alg_face_detect.h"
#include "FaceSDK_Api.h"
#include <exception>
#include <QDebug>

CAlgFaceDetect::CAlgFaceDetect()
{

}
CAlgFaceDetect:: ~CAlgFaceDetect()
{

}

bool CAlgFaceDetect::faceAlgGetFea(unsigned char* rgb24,int nW,int nH,FacePointInfo& ptInfo,unsigned char* szFea)
{
    BOOL b = FaceSDK_GetFeatrueEx(0,rgb24,nW,nH,ptInfo,szFea);
    if(b)
        return true;
    else {
        return false;
    }
}

int CAlgFaceDetect::faceAlgDetect(unsigned char* rgb24,int nW,int nH,RECT rc[1024],FacePointInfo ptInfo[1024])
{
//    qDebug() << "begin faceAlgDetect" ;
    int nRet = 0;
    try{
         nRet = FaceSDK_DetectFaceEx(0, rgb24, nW, nH, rc, ptInfo,30);
    }catch(std::exception e)
    {
        qDebug()<<e.what();
    }

    return nRet;
}

float CAlgFaceDetect::faceAlgCompare(unsigned char* szFea1,unsigned char* szFea2)
{
    float fRet = FaceSDK_CompareFeatrue(0, szFea1, szFea2);
    return fRet;
}

bool CAlgFaceDetect::init()
{
    BOOL nInit = FaceSDK_Init();
    if(nInit)
    {
        qDebug() << "FaceSDK_Init success";
        return true;
    }
    return false;
}
