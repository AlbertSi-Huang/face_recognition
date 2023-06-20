#pragma once
#ifdef COAT_SDK_EXPORTS
#define COAT_SDK_API __declspec(dllexport)
#include "Manage.h"
#else
#define COAT_SDK_API __declspec(dllimport)
#define ONE_THREAD
#endif
#include <Windows.h>


#ifndef COAT_SDK_EXPORTS

typedef enum _CoatType {
	CoatType_reflective = 0,
	CoatType_unknow
} CoatType;

typedef struct _CoatRectInfo {
	RECT rc;
	int nType;
	int nScroe;
} CoatRectInfo;

#endif






COAT_SDK_API BOOL WINAPI CoatSDK_Init();
COAT_SDK_API void WINAPI CoatSDK_Uninit();

COAT_SDK_API int  WINAPI CoatSDK_Detect(DWORD nThreadID, BYTE* pRgb24Buf, int nWidth, int nHeight, CoatRectInfo info[1024], BOOL bDebug);

COAT_SDK_API BOOL WINAPI CoatSDK_TestLicense();
COAT_SDK_API char* WINAPI CoatSDK_AlgVer();


