#include <direct.h>
#include <iostream>
#include "cv.h"
#include "opencv2/opencv.hpp"
#include <io.h>
using namespace std;
using namespace cv;

//输入一个视频的路径，一个用于存图像的路径，在存图的文件夹下生成图像
int VideoImageWrite(string videoPath, string folderPath ) {
	
	VideoCapture cap(videoPath);
	//
	if (0 != access(folderPath.c_str(), 0))
	{
		// if this folder not exist, create a new one.
		mkdir(folderPath.c_str());   // 返回 0 表示创建成功，-1 表示失败
									 //换成 ::_mkdir  ::_access 也行，不知道什么意思
	}
	else {
		cout << "Directory already exists." << endl;
	}
	// 获取视频总帧数
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

	return 1;
}

//// 描述：将视频帧转成图片输出
//int main()
//{
//	// 获取视频文件
//	string videoPath = "E:/project/image/TestData/video/8_3.mp4";
//	string folderPath = "E:/project/image/TestData/video/8_3/";
//	
//	VideoImageWrite(videoPath, folderPath);
//
//	system("pause");
//
//	return 0;
//}