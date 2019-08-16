#include <stdio.h>
#include <io.h>
#include <string>
#include <fstream> 
#include <direct.h>
#include <iostream>
#include <io.h>
#include "VideoProcess.h"

using namespace std;

//int main(int argc, char* argv[])
//{
//
//	int fileCounter; //用来统计特定文件个数的文件计数器；
//
//					 //需要统计特定的文件类型，例如bmp文件;
//	char *fileNamePath = "E://00_RD_BMPs//03_ImggrayRsd//*.bmp";
//
//	//调用函数GetDesignateFilesNumber，统计该文件夹中指定的文件个数；
//	fileCounter = GetDesignateFilesNumber(fileNamePath);
//
//	//输出统计结果
//	cout << "该文件夹中，bmp文件个数为：" << fileCounter << endl;
//
//	////////
//	return 0;
//
//}


int GetDesignateFilesNumber(string fileNamePath)
{
	int fileCounter = 0;  //用来统计特定文件个数的文件计数器；

	struct _finddata_t fileInfo;
	intptr_t handle = _findfirst(fileNamePath.c_str(), &fileInfo);

	if (handle == -1L)
	{
		cerr << "failed to transfer files" << endl;
		return -1;
	}

	do
	{
		fileCounter++;  //计数器加1;
						//cout<<fileInfo.name <<endl;  //输出文件名；

	} while (_findnext(handle, &fileInfo) == 0);


	//////////

	return fileCounter;

}