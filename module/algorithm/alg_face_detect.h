#ifndef ALG_FACE_DETECT_H
#define ALG_FACE_DETECT_H
#include "FaceSDK_Api.h"
class CAlgFaceDetect
{
public:
    static CAlgFaceDetect signle()
    {
        static CAlgFaceDetect s;
        return s;
    }
    virtual ~CAlgFaceDetect();
    bool init();
    int faceAlgDetect(unsigned char* rgb24,int nW,int nH,RECT rc[1024],FacePointInfo ptInfo[1024]);
    bool faceAlgGetFea(unsigned char* rgb24,int nW,int nH,FacePointInfo& ptInfo,unsigned char* szFea);
    float faceAlgCompare(unsigned char* szFea1,unsigned char* szFea2);
private:
    CAlgFaceDetect();

};

#endif // ALG_FACE_DETECT_H
