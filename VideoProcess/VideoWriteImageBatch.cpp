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

//����Ƶ�ļ��ĸ�Ŀ¼���Ϳ���������Ϊ���mp4�ļ�����ͼ�����ɵ�ͼ�񱣴浽����Ƶ���������ļ����й�
int VideoWriteImageBatch(string filePath) {
	string inPath = filePath + "*.mp4";//�����ļ����µ������ļ�
									   //���ڲ��ҵľ��
	std::string::size_type nPos1 = std::string::npos;
	intptr_t handle = 0;
	struct _finddata_t fileinfo;
	//��һ�β���
	handle = _findfirst(inPath.c_str(), &fileinfo);
	if (handle == -1)
		return -1;
	do
	{
		//�½��ļ���
		nPos1 = (string(fileinfo.name)).find_last_of(".");
		string folderPath = filePath + (string(fileinfo.name)).substr(0, nPos1) + "/";
		cout << (string(fileinfo.name)).substr(0, nPos1) << endl;
		if (0 != access(folderPath.c_str(), 0))
		{
			// if this folder not exist, create a new one.
			mkdir(folderPath.c_str());   // ���� 0 ��ʾ�����ɹ���-1 ��ʾʧ��
										 //���� ::_mkdir  ::_access Ҳ�У���֪��ʲô��˼
		}
		else {
			cout << "Directory already exists." << endl;
		}

		string mp4Path = filePath + string(fileinfo.name);
		VideoCapture cap(mp4Path);
		cout << mp4Path << endl;
		//��ȡ��Ƶ��֡��
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

	} while (!_findnext(handle, &fileinfo));

	_findclose(handle);

	return 1;
}

//// ����������Ƶ֡ת��ͼƬ���
//int main()
//{
//	//Ŀ���ļ���·��
//	string filePath = "E:/project/interface/2019-08-27/test_ssim/testData/";
//	
//	VideoWriteImageBatch(filePath);
//	
//	system("pause");
//	return 0;
//}
