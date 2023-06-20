#pragma once
#ifdef SFACE_EXPORTS
#define SFACE_API __declspec(dllexport)
#include "Manage.h"
#else
#define SFACE_API __declspec(dllimport)
#define ONE_THREAD
#endif
#include <Windows.h>



#ifndef SFACE_EXPORTS
typedef enum _HelmetType {
	Helmet = 0,
	None,
} HelmetType;

typedef struct _HelmetRectInfo {
	RECT rc;
        int nType;
        int nScroe;
} HelmetRectInfo;

#endif






SFACE_API BOOL WINAPI HelmetSdk_Init();
SFACE_API void WINAPI HelmetSdk_Uninit();

SFACE_API int  WINAPI HelmetSdk_Detect(DWORD nThreadID, BYTE* pRgb24Buf, int nWidth, int nHeight, HelmetRectInfo info[1024], BOOL bDebug);

SFACE_API BOOL WINAPI HelmetSdk_TestLicense();
SFACE_API char* WINAPI HelmetSdkObjdSDK_AlgVer();


