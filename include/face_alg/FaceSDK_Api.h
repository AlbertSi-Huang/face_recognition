#pragma once
#ifdef SFACE_EXPORTS
#define SFACE_API __declspec(dllexport)
#else
#define SFACE_API __declspec(dllimport)
#define ONE_THREAD
#endif
#include <Windows.h>


#ifndef SFACE_EXPORTS
typedef struct _FaceRectInfo {
        RECT rc;
        double roll;
        double pitch;
        double yaw;
        double score; /**< Larger score should mean higher confidence. */
} FaceRectInfo;

typedef struct _FacePointInfo {
        POINT ptEyeLeft;
        POINT ptEyeRight;
        POINT ptNose;
        POINT ptMouthLeft;
        POINT ptMouthRight;
        int count;
        POINT KeyPoint[256];
} FacePointInfo;
#endif


SFACE_API BOOL WINAPI FaceSDK_Init();
SFACE_API void WINAPI FaceSDK_Uninit();
SFACE_API int  WINAPI FaceSDK_GetFeatrueSize();

SFACE_API int  WINAPI FaceSDK_DetectFace(DWORD nThreadID, BYTE* pRgb8Buf, int nWidth, int nHeight, RECT rcInfo[1024], FacePointInfo ptInfo[1024], int nGrade);
SFACE_API BOOL WINAPI FaceSDK_IsGlasses(DWORD nThreadID, BYTE* pRgb8Buf, int nWidth, int nHeight, FacePointInfo info);
SFACE_API BOOL WINAPI FaceSDK_GetFeatrue(DWORD nThreadID, BYTE* pRgb8Buf, int nWidth, int nHeight, FacePointInfo ptInfo, BYTE pFea[8192]);

SFACE_API int  WINAPI FaceSDK_DetectFaceEx(DWORD nThreadID, BYTE* pRgb24Buf, int nWidth, int nHeight, RECT rcInfo[1024], FacePointInfo ptInfo[1024], int nGrade);
SFACE_API BOOL WINAPI FaceSDK_IsGlassesEx(DWORD nThreadID, BYTE* pRgb24Buf, int nWidth, int nHeight, FacePointInfo info);
SFACE_API BOOL WINAPI FaceSDK_GetFeatrueEx(DWORD nThreadID, BYTE* pRgb24Buf, int nWidth, int nHeight, FacePointInfo ptInfo, BYTE pFea[8192]);

SFACE_API float WINAPI FaceSDK_CompareFeatrue(DWORD nThreadID, BYTE *pFea1, BYTE *pFea2);
SFACE_API BOOL WINAPI FaceSDK_TestLicense();
SFACE_API char* WINAPI FaceSDK_AlgVer();


