#include <direct.h>
#include <iostream>
#include "cv.h"
#include "opencv2/opencv.hpp"
#include <io.h>
using namespace std;
using namespace cv;

//����һ����Ƶ��·����һ�����ڴ�ͼ���·�����ڴ�ͼ���ļ���������ͼ��
int VideoImageWrite(string videoPath, string folderPath ) {
	
	VideoCapture cap(videoPath);
	//
	if (0 != access(folderPath.c_str(), 0))
	{
		// if this folder not exist, create a new one.
		mkdir(folderPath.c_str());   // ���� 0 ��ʾ�����ɹ���-1 ��ʾʧ��
									 //���� ::_mkdir  ::_access Ҳ�У���֪��ʲô��˼
	}
	else {
		cout << "Directory already exists." << endl;
	}
	// ��ȡ��Ƶ��֡��
	long totalFrameNumber = cap.get(CV_CAP_PROP_FRAME_COUNT);
	cout << "total frames: " << totalFrameNumber << endl;

	Mat frame;
	bool flags = true;
	long currentFrame = 1;

	while (flags) {
		
		// ��ȡ��Ƶÿһ֡
		cap.read(frame);
		stringstream str;
		str << currentFrame << ".png";
		cout << "���ڴ����" << currentFrame << "֡" << endl;
		printf("\n");

		// ����ÿ1֡��ȡһ��֡
		if (currentFrame % 1 == 0) {
			// ��֡ת��ͼƬ���
			imwrite(folderPath + str.str(), frame);
		}

		// ��������
		if (currentFrame >= totalFrameNumber) {
			flags = false;
		}
		currentFrame++;
	}

	return 1;
}

//// ����������Ƶ֡ת��ͼƬ���
//int main()
//{
//	// ��ȡ��Ƶ�ļ�
//	string videoPath = "E:/project/image/TestData/video/8_3.mp4";
//	string folderPath = "E:/project/image/TestData/video/8_3/";
//	
//	VideoImageWrite(videoPath, folderPath);
//
//	system("pause");
//
//	return 0;
//}