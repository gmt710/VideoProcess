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


//����Ƶ�ļ��ĸ�Ŀ¼���Ϳ���������Ϊ���Ŀ¼�µ�ͼ������avi�ļ�
int ImageWriteVideoBatch(string filePath) {

	string inPath = filePath + "*";//�����ļ����µ������ļ�
	intptr_t handle = 0;//���ڲ��ҵľ��
	struct _finddata_t fileinfo;
	//��һ�β���
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
// ����������Ƶ֡ת��ͼƬ���
int main()
{
	//Ŀ���ļ���·��
	string filePath = "E:/project/huawei/image/TestData/imageResult/";

	ImageWriteVideoBatch(filePath);

	system("pause");
	return 0;
}
