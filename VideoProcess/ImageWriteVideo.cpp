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

//����ͼ���Ŀ¼����һ��ͼ��·������Ƶ���ƣ���Ƶ֡������
//�����Ƶ
int ImageWriteVideo(const char *imagePath, const char *firstImage, string videoName, int videoNum)
{
	char imageName[300];
	Mat src;
	Mat frame;
	Mat src0 = imread(firstImage);
	resize(src0, src0, Size(640, 360), 0, 0, INTER_LINEAR);
	Size size = src0.size();
	VideoWriter writer(videoName, CV_FOURCC('M', 'J', 'P', 'G'), 25, size, true);

	for (int i = 2; i < videoNum; i++) {
		sprintf_s(imageName, "%s%d%s", imagePath, i, ".png");
		src = imread(imageName);
		resize(src, src, Size(640, 360), 0, 0, INTER_LINEAR);

		if (src.empty()) {
			cout << "error in read picture" << endl;
			return -1;
		}
		writer.write(src);
		
	}
	cout << "==================================success to write video=================================\n" << endl;
	return 1;
}

//// ��������ͼ��ת����Ƶ���
//int main()
//{
//	char imagePath[300] = "E:/c++work/tf_demo/output_data/512/ImageManFinger/";
//	char firstImage[300] = "E:/c++work/tf_demo/output_data/512/ImageManFinger/1.png";
//	const string videoName = "ImageManFinger512.avi";
//	int videoNum = 437;
//	int flag = ImageWriteVideo(imagePath, firstImage, videoName, videoNum);
//	if (flag == 1)
//		cout << "finished video writing��" << endl;
//	else
//		cout << "error video writing��" << endl;
//
//	
//	system("PAUSE");
//	return 0;
//
//}
