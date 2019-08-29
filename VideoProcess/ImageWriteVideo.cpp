#include<opencv2/opencv.hpp>
#include <stdio.h>
#include <io.h>
#include <string>
#include <iostream>  
#include <fstream> 
# include<string.h>
#include "windows.h"
#include "VideoProcess.h"

using namespace std;
using namespace cv;

//输入图像根目录，第一张图像路径，视频名称，视频帧数量；
//输出视频
int ImageWriteVideo(const char *imagePath, const char *firstImage, string videoName, int videoNum)
{
	char imageName[300];
	Mat src;
	Mat frame;
	Mat src0 = imread(firstImage);
	resize(src0, src0, Size(1280, 720), 0, 0, INTER_LINEAR);
	Size size = src0.size();
	VideoWriter writer(videoName, CV_FOURCC('M', 'J', 'P', 'G'), 25, size, true);

	for (int i = 3; i < videoNum; i++) {
		sprintf_s(imageName, "%s%04d%s", imagePath, i, ".png");
		src = imread(imageName);
		resize(src, src, Size(1280, 720), 0, 0, INTER_LINEAR);

		if (src.empty()) {
			cout << "error in read picture" << endl;
			return -1;
		}
		writer.write(src);
		
	}
	cout << "==================================success to write video=================================\n" << endl;
	return 1;
}

//// 描述：将图像转成视频输出
//int main()
//{
//	char imagePath[300] = "E:/project/interface/2019-08-27/test_ssim/testData/test_ssim_finger/";
//	char firstImage[300] = "E:/project/interface/2019-08-27/test_ssim/testData/test_ssim_finger/0003.png";
//	const string videoName = "test_ssim_finger.avi";
//	int videoNum = 2400-3+1;
//	int flag = ImageWriteVideo(imagePath, firstImage, videoName, videoNum);
//	if (flag == 1)
//		cout << "finished video writing！" << endl;
//	else
//		cout << "error video writing！" << endl;
//
//	
//	system("PAUSE");
//	return 0;
//
//}
