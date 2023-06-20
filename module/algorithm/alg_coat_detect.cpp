#include "alg_coat_detect.h"
#include <string>
#include <iostream>
#include <exception>
using namespace std;

CAlgCoatDetct::~CAlgCoatDetct()
{

}

CAlgCoatDetct::CAlgCoatDetct(){}

bool CAlgCoatDetct::init()
{
    BOOL b = CoatSDK_Init();
    if(b)
    {
        return true;
    }
    return false;
}

int CAlgCoatDetct::coatAlgDetect(unsigned char* rgb24,int nW,int nH,CoatRectInfo info[10])
{
    int nRet = 0;
    try{
        bool bDebug = false;
        nRet = CoatSDK_Detect(0, rgb24, nW, nH,info,bDebug);
    }catch(std::exception e)
    {
        std::cout << e.what() <<std::endl;
    }

    return nRet;
}


void CAlgCoatDetct::unInit()
{
    CoatSDK_Uninit();
}
