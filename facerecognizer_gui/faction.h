#ifndef FACTION_H
#define FACTION_H

#include<opencv2\core.hpp>
#include<opencv2\highgui.hpp>
#include<opencv2\imgproc.hpp>

#include<opencv2\opencv.hpp>  
#include<opencv2\face.hpp>
#include<opencv2\core\core.hpp>
#include<opencv2\face\facerec.hpp>
#include <opencv2/highgui/highgui_c.h>//CV_Error的头文件

//使用void read_csv()这个函数必须的三个头文件
#include <fstream>  
#include <sstream> 
#include <iostream>

#include <vector>
#include<stdio.h>
#include<math.h>
#include <opencv2\imgproc\types_c.h>

#include "facerecognizer_gui.h"
#include "putText.h"
using namespace std;
using namespace cv;
using namespace cv::face;


//简单照相
void takephoto(int number);
//拍照并进行加工处理
//转灰度 裁剪大小为92*112
int takephoto_2(void);
//人脸检测1 返回1为成功 返回0为失败
int detectAndDisplay(Mat frame);
//人脸检测2 返回1为成功 返回0为失败
int PictureOrVidoe(void);
//检测人脸 拍照转化成灰度 大小为92*112 十张
int takephoto_2(void);

Mat norm_0_255(InputArray _src);
//读取csv文件
void read_csv(const string& filename, vector<Mat>& images,
	vector<int>& labels, char separator);
//进行训练 生成xml文件
int TrainAndXml(void);
//识别图片 返回识别的序号
int Predict(Mat src_image);
//人脸识别 返回1为正确 0为错误
//int faceconregnizer(void);

#endif