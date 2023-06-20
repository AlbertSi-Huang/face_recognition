#ifndef ALG_COAT_DETECT_H
#define ALG_COAT_DETECT_H
#include "CoatSdk_Api.h"

class CAlgCoatDetct
{
public:
    static CAlgCoatDetct signle()
    {
        static CAlgCoatDetct s;
        return s;
    }
    virtual ~CAlgCoatDetct();
    bool init();
    int coatAlgDetect(unsigned char* rgb24,int nW,int nH,CoatRectInfo info[10]);
    void unInit();
    //CoatSDK_Detect( BYTE* pRgb24Buf, int nWidth, int nHeight, CoatRectInfo info[1024]);
private:
    CAlgCoatDetct();
};

#endif // ALG_COAT_DETECT_H
