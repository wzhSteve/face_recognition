#pragma once
#ifndef FACERECOGNIZER_GUI_H
#define FACERECOGNIZER_GUI_H

//qt
#include <QtWidgets/QMainWindow>
#include "ui_facerecognizer_gui.h"
#include <qtimer.h>
#include<QGraphicsScene>  
#include<QGraphicsView>                   //graphicsview类
#include <qfiledialog.h>                //getopenfilename 类申明
#include <qlabel.h>                     //label类
#include <qtextedit.h>
#include <qmovie.h>
#include <qsize.h>
#include <qdialog.h>
#include <qmessagebox.h>
#include "putText.h"
//人脸识别
#include "faction.h"
#include <map>
#include <stdio.h>
#include <io.h>
#include <string>
#include <vector>
#include<algorithm>
#include <iostream>
#include <sstream>
#include <fstream>
#include<direct.h> 

using namespace std;
using namespace cv;
using namespace cv::face;

class facerecognizer_gui : public QMainWindow
{
	Q_OBJECT

public:
	facerecognizer_gui(QWidget *parent = Q_NULLPTR);
	~facerecognizer_gui();

private:
	Ui::facerecognizer_guiClass ui;
	Mat image;

	QLabel* label_3;

	QTextEdit* EnterLabel;
private slots:
	void ShowButton_clicked();
	void TakePhoto_clicked();//若函数为on_名字_clicked() 会触发两次 注意
	void Train_clicked();
	void CloseCarmera_clicked();
	void closeEvent(QCloseEvent* e);
};
//Label显示Mat图像
void LabelDisplayMat(QLabel* label, cv::Mat& mat);
void InitLabelName();
//获得目标文件夹下的所有文件夹名 存入向量中
void getSubdirs(std::string path, std::vector<std::string>& files);
//sort的bool参数
bool sort_fun(const string& p1, const string& p2);
//返回目标文件夹下的文件夹名中数字最大的值
int back_file_number();
//outi:为新建文件夹的的名字
//label:标签 int类型 
void write_at(int outi, int label);
//string 转化成int型
int StringToInt(string a);
#endif