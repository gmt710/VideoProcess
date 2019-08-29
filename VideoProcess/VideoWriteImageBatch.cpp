#include <stdio.h>
#include <io.h>
#include <string>
#include <fstream> 
#include <direct.h>
#include <iostream>
#include "opencv2/opencv.hpp"
#include <io.h>

using namespace std;
using namespace cv;

//给视频文件的根目录，就可以批处理为多个mp4文件生成图像，生成的图像保存到以视频名命名的文件夹中国
int VideoWriteImageBatch(string filePath) {
	string inPath = filePath + "*.mp4";//遍历文件夹下的所有文件
									   //用于查找的句柄
	std::string::size_type nPos1 = std::string::npos;
	intptr_t handle = 0;
	struct _finddata_t fileinfo;
	//第一次查找
	handle = _findfirst(inPath.c_str(), &fileinfo);
	if (handle == -1)
		return -1;
	do
	{
		//新建文件夹
		nPos1 = (string(fileinfo.name)).find_last_of(".");
		string folderPath = filePath + (string(fileinfo.name)).substr(0, nPos1) + "/";
		cout << (string(fileinfo.name)).substr(0, nPos1) << endl;
		if (0 != access(folderPath.c_str(), 0))
		{
			// if this folder not exist, create a new one.
			mkdir(folderPath.c_str());   // 返回 0 表示创建成功，-1 表示失败
										 //换成 ::_mkdir  ::_access 也行，不知道什么意思
		}
		else {
			cout << "Directory already exists." << endl;
		}

		string mp4Path = filePath + string(fileinfo.name);
		VideoCapture cap(mp4Path);
		cout << mp4Path << endl;
		//获取视频总帧数
		long totalFrameNumber = cap.get(CV_CAP_PROP_FRAME_COUNT);
		cout << "total frames: " << totalFrameNumber << endl;
		Mat frame;
		bool flags = true;
		long currentFrame = 1;

		while (flags) {
			// 读取视频每一帧
			cap.read(frame);
			stringstream str;
			str << currentFrame << ".png";
			cout << "正在处理第" << currentFrame << "帧" << endl;
			printf("\n");

			// 设置每1帧获取一次帧
			if (currentFrame % 1 == 0) {
				// 将帧转成图片输出
				imwrite(folderPath + str.str(), frame);
			}

			// 结束条件
			if (currentFrame >= totalFrameNumber) {
				flags = false;
			}
			currentFrame++;
		}

	} while (!_findnext(handle, &fileinfo));

	_findclose(handle);

	return 1;
}

//// 描述：将视频帧转成图片输出
//int main()
//{
//	//目标文件夹路径
//	string filePath = "E:/project/interface/2019-08-27/test_ssim/testData/";
//	
//	VideoWriteImageBatch(filePath);
//	
//	system("pause");
//	return 0;
//}
