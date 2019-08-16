#include <stdio.h>
#include <io.h>
#include <string>
#include <fstream> 
#include <direct.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include <io.h>
#include "VideoProcess.h"

using namespace std;
using namespace cv;


//给视频文件的根目录，就可以批处理为多个目录下的图像生成avi文件
int ImageWriteVideoBatch(string filePath) {

	string inPath = filePath + "*";//遍历文件夹下的所有文件
	intptr_t handle = 0;//用于查找的句柄
	struct _finddata_t fileinfo;
	//第一次查找
	handle = _findfirst(inPath.c_str(), &fileinfo);
	if (handle == -1) {
		return -1;
	}
	do
	{
		string folderPath = filePath + (string(fileinfo.name)) + "/";
		cout <<"=======================================Now Processing====================================\n" <<folderPath << endl;
		string firstImage = folderPath + "2.png";
		string videoName = folderPath + (string(fileinfo.name)) + ".avi";
		string ImagePath = folderPath + "*.png";
		//cout << ImagePath << endl;
		int videoNum = GetDesignateFilesNumber(ImagePath);
		if (videoNum == -1) {
			continue;
		}
		else {
			videoNum = videoNum + 1;
		}
		//cout << videoNum << endl;
		ImageWriteVideo((folderPath.c_str()), (firstImage.c_str()), videoName,  videoNum);

	} while (!_findnext(handle, &fileinfo));

	_findclose(handle);

	return 1;
}
// 描述：将视频帧转成图片输出
int main()
{
	//目标文件夹路径
	string filePath = "E:/project/huawei/image/TestData/imageResult/";

	ImageWriteVideoBatch(filePath);

	system("pause");
	return 0;
}
