#ifndef ALG_HELMET_DETECT_H
#define ALG_HELMET_DETECT_H
#include "HelmetSDK_Api.h"

class CAlgHelmetDetect
{
public:
    static CAlgHelmetDetect signle()
    {
        static CAlgHelmetDetect s;
        return s;
    }

    virtual ~CAlgHelmetDetect();
    bool init();
    int HelmetAlgDetect(unsigned char* rgb24,int nW,int nH,HelmetRectInfo info[1024]);
    void unInit();

private:
    CAlgHelmetDetect();
};

#endif // ALG_HELMET_DETECT_H
