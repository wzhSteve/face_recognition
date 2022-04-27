#include "facerecognizer_gui.h"

//label 与人名存储的字典
map<int,string> LabelName;
string LabelString = "wzh";
int map_size = 0;//map_size为map中含有的数量

extern String face_cascade_name;
extern String eyes_cascade_name;
extern String window_name;
extern String picture_name;
extern String haarcascade_frontalface_alt2;
extern String haarcascade_frontalface_alt2;
RNG g_rng(12345);
extern Ptr<FaceRecognizer> model;
extern int NumberOfPeople;
//检测是否关闭摄像头
//1 为关闭 0 为打开
int flag = 0;

VideoCapture cap;

void getSubdirs(std::string path, std::vector<std::string>& files)
{
	long long hFile = 0;//注意如果是long handle则在64位下会出现异常
	struct _finddata_t fileinfo;
	std::string p;
	if ((hFile = _findfirst(p.assign(path).append("/*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
					files.push_back(fileinfo.name);
				//printf(fileinfo.name);
				//printf("\n");
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}
//sort的bool参数
bool sort_fun(const string& p1, const string& p2)
{
	stringstream stream;
	int number1 = 0, number2 = 0;
	stream << p1; stream >> number1; stream.clear();
	stream << p2; stream >> number2; stream.clear();
	return number1 > number2;//升序排列  
}
//返回目标文件夹下的文件夹名中数字最大的值
int back_file_number()
{
	//string inPath = "H:/face_database/";
	string inPath = "Resources/face_database/";
	vector<string> filename;
	getSubdirs(inPath, filename);
	sort(filename.begin(), filename.end(), sort_fun);
	string out = *filename.begin();
	return StringToInt(out);
}
//outi:为新建文件夹的的名字
//label:标签 int类型 
void write_at(int outi, int enterlabel)
{
	int i = 1;
	//ofstream outfile("H:/face_database/at.txt", ofstream::app);
	ofstream outfile("Resources/face_database/at.txt", ofstream::app);
	//string temp = "H:\\face_database";
	string temp = "Resources\\face_database";
	string dirName = temp + "\\" + to_string(outi);
	_mkdir(dirName.c_str());//_mkdir()创建成功返回0，失败返回-1。
	while (i != 11)
	{
		outfile << temp << "\\" << outi << "\\" << i << ".pgm;" << enterlabel << ";" << LabelName[outi] << endl;
		i++;
	}
	outfile.close();
}
int StringToInt(string a)
{
	int ai = 0;
	stringstream stream;
	stream << a;
	stream >> ai;
	stream.clear();
	return ai;
}
void InitLabelName()
{
	ifstream file("Resources/face_database/at.txt", ifstream::in);
	string line;
	while (getline(file, line)) //从文本文件中读取一行字符，未指定限定符默认限定符为“/n”
	{
		char separator = ';';
		string path;
		string classlabel;
		string name;
		stringstream liness(line);//这里采用stringstream主要作用是做字符串的分割
		getline(liness, path, separator);//读入图片文件路径以分好作为限定符
		getline(liness, classlabel,separator);//读入图片标签，默认限定符
		getline(liness, name);
		if (!path.empty() && !classlabel.empty()) //如果读取成功，则将图片和对应标签压入对应容器中
		{
			//将Label和name加入字典
			LabelName[StringToInt(classlabel)] = name;
			map_size++;
		}
	}
	file.close();
}
facerecognizer_gui::facerecognizer_gui(QWidget *parent)
	: QMainWindow(parent)
{
	InitLabelName();
	// setupUi(this)是由.ui文件生成的类的构造函数，作用是对界面进行初始化，
// 它按照Qt设计器里设计的样子把窗体画出来，把Qt设计器里面定义的信号和槽建立起来。
// 也可以说，setupUi是界面和写程序之间的桥梁。
	ui.setupUi(this);
	QIcon icon;
	//icon.addFile(tr("F:/vs_file/facerecognizer_gui/facerecognizer_gui/Resources/open_camera.jpg"));
	icon.addFile(tr("Resources/open_camera.jpg"));
	ui.ShowButton->setIcon(icon);
	ui.ShowButton->setIconSize(QSize(100, 30));
	//icon.addFile(tr("F:/vs_file/facerecognizer_gui/facerecognizer_gui/Resources/close_camera.jpg"));
	icon.addFile(tr("Resources/close_camera.jpg"));
	ui.CloseCamera->setIcon(icon);
	ui.CloseCamera->setIconSize(QSize(100, 30));
	//icon.addFile(tr("F:/vs_file/facerecognizer_gui/facerecognizer_gui/Resources/takephoto.jpg"));
	icon.addFile(tr("Resources/takephoto.jpg"));
	ui.TakePhoto->setIcon(icon);
	ui.TakePhoto->setIconSize(QSize(100, 30));
	//icon.addFile(tr("F:/vs_file/facerecognizer_gui/facerecognizer_gui/Resources/train.jpg"));
	icon.addFile(tr("Resources/train.jpg"));
	ui.Train->setIcon(icon);
	ui.Train->setIconSize(QSize(100, 30));

	//QMovie* movie = new QMovie("F:/vs_file/facerecognizer_gui/facerecognizer_gui/Resources/knk.gif");
	QMovie* movie = new QMovie("Resources/knk.gif");
	ui.label_10->setMovie(movie);
	movie->start();

}
facerecognizer_gui::~facerecognizer_gui()
{
	if (cap.isOpened())cap.release();
}
void facerecognizer_gui::ShowButton_clicked()
{
	if (!cap.isOpened())//避免了与takephoto同时进行
	{
		ui.ShowButton->setEnabled(false);
		QIcon icon;
		icon.addFile(tr("Resources/open_camera_down.jpg"));
		ui.ShowButton->setIcon(icon);
		ui.ShowButton->setIconSize(QSize(100, 30));
		icon.addFile(tr("Resources/close_camera.jpg"));
		ui.CloseCamera->setIcon(icon);
		ui.CloseCamera->setIconSize(QSize(100, 30));
		cap.open(0);    //打开默认摄像头  
		if (!cap.isOpened()) {}
		Mat frame;
		Mat gray;
		//这个分类器是人脸检测所用
		CascadeClassifier cascade;
		bool stop = false;
		//训练好的文件名称，放置在可执行文件同目录下  
		cascade.load(haarcascade_frontalface_alt2);
		//感觉用lbpcascade_frontalface效果没有它好，注意哈！要是正脸
		model = FisherFaceRecognizer::create();
		//1.加载训练好的分类器
		//model->read("H:/xml_file/PCA_train.xml");
		model->read("Resources/xml_file/PCA_train.xml");
		// opencv2用read
		//3.利用摄像头采集人脸并识别
		while (!flag)
		{
			cap >> frame;
			vector<Rect> faces(0);//建立用于存放人脸的向量容器
			cvtColor(frame, gray, CV_RGB2GRAY);//转化为灰度图
			equalizeHist(gray, gray); //变换后的图像进行直方图均值化处理  
			//检测人脸
			cascade.detectMultiScale(gray, faces, 1.1, 4, 0);
			Mat* pImage_roi = new Mat[faces.size()];    //定以数组
			Mat face;
			Point text_lb;//文本写在的位置
			//框出人脸
			string str;
			for (int i = 0; i < faces.size(); i++)
			{
				pImage_roi[i] = gray(faces[i]); //将所有的脸部保存起来
				text_lb = Point(faces[i].x, faces[i].y);
				if (pImage_roi[i].empty())continue;
				//获取对应的label
				int key = Predict(pImage_roi[i]);
				if (LabelName.find(key) != LabelName.end())
					str = LabelName[key];
				else str = "陌生人";
				Scalar color = Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255));//所取的颜色任意值
				rectangle(frame, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), color, 1, 8);//放入缓存
				//putText(frame, str, text_lb, FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255));//添加文字
				putTextZH(frame, str.c_str(), text_lb, Scalar(255, 0, 0), 20, "华文行楷");
			}

			delete[]pImage_roi;
			waitKey(200);
			LabelDisplayMat(ui.label, frame);
			if (flag)
			{
				flag = 0;
				icon.addFile(tr("Resources/open_camera.jpg"));
				ui.ShowButton->setIcon(icon);
				ui.ShowButton->setIconSize(QSize(100, 30));
				ui.label->setPixmap(QPixmap(tr("Resources/cameraback.jpg")));
				break;
			}
		}

	if (cap.isOpened())
		cap.release();//摄像头关闭
	ui.ShowButton->setEnabled(true);
	}
	
}
void facerecognizer_gui::CloseCarmera_clicked()
{
	ui.CloseCamera->setEnabled(false);
	QIcon icon;
	//icon.addFile(tr("F:/vs_file/facerecognizer_gui/facerecognizer_gui/Resources/close_camera_down.jpg"));
	icon.addFile(tr("Resources/close_camera_down.jpg"));
	ui.CloseCamera->setIcon(icon);
	ui.CloseCamera->setIconSize(QSize(100, 30));
	flag = 1;
	if (cap.isOpened())
	cap.release();//摄像头关闭
	ui.CloseCamera->setEnabled(true);
}
void facerecognizer_gui::TakePhoto_clicked()
{
	//获取textEdit中的文本
	QString strTxtEdt = ui.name->toPlainText();
	if (strTxtEdt == "")
	{
		QMessageBox::warning(NULL, "warning", "if you do not enter your name,sorry you will stay here",
			QMessageBox::Yes);
	}
	else if (!cap.isOpened())//避免与showButton同时使用摄像头
	{
		LabelString = strTxtEdt.toStdString();
		ui.TakePhoto->setEnabled(false);
		QIcon icon;
		icon.addFile(tr("Resources/takephoto_down.jpg"));
		ui.TakePhoto->setIcon(icon);
		ui.TakePhoto->setIconSize(QSize(100, 30));
	
		QString a;
		//目标文件夹下的文件夹数目
		int outi = back_file_number() + 1;

		//将label与名字存入map中 方便后边查询
		LabelName[outi] = LabelString;
		map_size++;

		//建立文件夹并更新at.txt
		write_at(outi, outi);
		CascadeClassifier cascada;
		cascada.load(haarcascade_frontalface_alt2);
		cap.open(0);
		Mat frame, myFace;
		int pic_num = 1;

		a = "taking";
		ui.label_3->setText(a);

		while (1) {
			//摄像头读图像
			cap >> frame;
			vector<Rect> faces;//vector容器存检测到的faces
			Mat frame_gray;
			cvtColor(frame, frame_gray, COLOR_BGR2GRAY);//转灰度化，减少运算
			cascada.detectMultiScale(frame_gray, faces, 1.1, 4, 0);
			printf("检测到人脸个数：%d\n", (int)faces.size());
			for (int i = 0; i < faces.size(); i++)
			{
				rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
			}
			//当只有一个人脸时，开始拍照
			if (faces.size() == 1)
			{
				Mat faceROI = frame_gray(faces[0]);//在灰度图中将圈出的脸所在区域裁剪出
				//faces[0]即为检测到的唯一的人脸的矩阵
				cv::resize(faceROI, myFace, Size(92, 112));//将faceROI裁为92*112赋值给myFace
				putText(frame, to_string(pic_num), faces[0].tl(), 3, 1.2, (0, 0, 225), 2, 0);//在 faces[0].tl()的左上角上面写序号
				string filename = format("Resources/face_database/%d/%d.pgm", outi, pic_num);
				imwrite(filename, myFace);//存在当前目录下

				LabelDisplayMat(ui.photo, myFace);
				waitKey(500);//等待500us
				pic_num++;//序号加1
				if (pic_num == 11)
				{
					break;//当序号为11时退出循环
				}
			}

		}
		a = "over";
		ui.label_3->setText(a);
		icon.addFile(tr("Resources/takephoto.jpg"));
		ui.TakePhoto->setIcon(icon);
		ui.TakePhoto->setIconSize(QSize(100, 30));
		ui.photo->setPixmap(QPixmap(tr("Resources/photoback.jpg")));
		cap.release();
		ui.TakePhoto->setEnabled(true);
	}
	
}
void facerecognizer_gui::Train_clicked()
{
	QString a;
	a = "training";
	ui.label_6->setText(a);
	ui.Train->setEnabled(false);
	QIcon icon;
	//icon.addFile(tr("F:/vs_file/facerecognizer_gui/facerecognizer_gui/Resources/train_down.jpg"));
	icon.addFile(tr("Resources/train_down.jpg"));
	ui.Train->setIcon(icon);
	ui.Train->setIconSize(QSize(100, 30));
	TrainAndXml();
	a = "over";
	ui.label_6->setText(a);
	//icon.addFile(tr("F:/vs_file/facerecognizer_gui/facerecognizer_gui/Resources/train.jpg"));
	icon.addFile(tr("Resources/train.jpg"));
	ui.Train->setIcon(icon);
	ui.Train->setIconSize(QSize(100, 30));
	ui.Train->setEnabled(true);
}
void LabelDisplayMat(QLabel* label, cv::Mat& mat)
{
	cv::Mat Rgb;
	QImage Img;
	if (mat.channels() == 3)//RGB Img
	{
		cv::cvtColor(mat, Rgb, CV_BGR2RGB);//颜色空间转换
		Img = QImage((const uchar*)(Rgb.data), Rgb.cols, Rgb.rows, Rgb.cols * Rgb.channels(), QImage::Format_RGB888);
	}
	else//Gray Img
	{
		Img = QImage((const uchar*)(mat.data), mat.cols, mat.rows, mat.cols * mat.channels(), QImage::Format_Indexed8);
	}
	label->setPixmap(QPixmap::fromImage(Img));
}
void facerecognizer_gui::closeEvent(QCloseEvent* e)
{
	if (cap.isOpened())cap.release();
}