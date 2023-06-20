#include "alg_helmet_detect.h"
#include <string>
#include <iostream>
#include <exception>
using namespace std;

CAlgHelmetDetect::~CAlgHelmetDetect()
{

}

CAlgHelmetDetect::CAlgHelmetDetect(){}
bool CAlgHelmetDetect::init()
{
    BOOL b = HelmetSdk_Init();
    if(b)
    {
        return true;
    }
    return false;
}

int CAlgHelmetDetect::HelmetAlgDetect(unsigned char* rgb24,int nW,int nH,HelmetRectInfo info[1024])
{
    int nRet = 0;
    bool bDebug = false;
    nRet = HelmetSdk_Detect(0, rgb24, nW, nH,info,bDebug);

    return nRet;
}

void CAlgHelmetDetect::unInit()
{
    HelmetSdk_Uninit();
}
