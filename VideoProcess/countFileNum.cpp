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
//	int fileCounter; //����ͳ���ض��ļ��������ļ���������
//
//					 //��Ҫͳ���ض����ļ����ͣ�����bmp�ļ�;
//	char *fileNamePath = "E://00_RD_BMPs//03_ImggrayRsd//*.bmp";
//
//	//���ú���GetDesignateFilesNumber��ͳ�Ƹ��ļ�����ָ�����ļ�������
//	fileCounter = GetDesignateFilesNumber(fileNamePath);
//
//	//���ͳ�ƽ��
//	cout << "���ļ����У�bmp�ļ�����Ϊ��" << fileCounter << endl;
//
//	////////
//	return 0;
//
//}


int GetDesignateFilesNumber(string fileNamePath)
{
	int fileCounter = 0;  //����ͳ���ض��ļ��������ļ���������

	struct _finddata_t fileInfo;
	intptr_t handle = _findfirst(fileNamePath.c_str(), &fileInfo);

	if (handle == -1L)
	{
		cerr << "failed to transfer files" << endl;
		return -1;
	}

	do
	{
		fileCounter++;  //��������1;
						//cout<<fileInfo.name <<endl;  //����ļ�����

	} while (_findnext(handle, &fileInfo) == 0);


	//////////

	return fileCounter;

}