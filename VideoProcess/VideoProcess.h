#ifndef VideoProcessDll_H_
#define VideoProcessDll_H_

#ifdef VideoProcessDll_EXPORTS
#define VideoProcessDll_API extern "C" _declspec(dllexport)
#else
#define VideoProcessDll_API extern "C" _declspec(dllimport)
#endif

#include<iostream>
using namespace std;

//�����ļ���Ӧ·����ͳ�Ƶõ��ļ���
//char *fileNamePath = "E://00_RD_BMPs//03_ImggrayRsd//*.bmp";
//fileCounter = GetDesignateFilesNumber(fileNamePath);

extern "C" _declspec(dllexport) int GetDesignateFilesNumber(string fileNamePath);
extern "C" _declspec(dllexport) int ImageWriteVideo(const char *imagePath, const char *firstImage, string videoName, int videoNum);

#endif 
