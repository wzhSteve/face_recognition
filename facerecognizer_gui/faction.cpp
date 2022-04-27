#include "faction.h"

Mat photo;
int i = 0;
/**.xml文件位置 */
String face_cascade_name = "Resources/haarcascades/haarcascade_frontalface_default.xml";
String eyes_cascade_name = "Resources/haarcascades/haarcascade_eye_tree_eyeglasses.xml";
String window_name = "Capture - Face detection";
String picture_name = "H:/lady.jpg";

//String face_cascade_name = "H:/opencv420/source/opencv/sources/data/haarcascades/haarcascade_frontalface_default.xml";
//String eyes_cascade_name = "H:/opencv420/source/opencv/sources/data/haarcascades/haarcascade_eye_tree_eyeglasses.xml";

String haarcascade_frontalface_alt2 = "Resources/haarcascades/haarcascade_frontalface_alt2.xml";

//RNG g_rng(12345);
Ptr<FaceRecognizer> model;
int NumberOfPeople = 1;//从1开始为输入人脸，前四十个为orl自带的人脸数据

//照相_照片数量
void takephoto(int number)
{
	VideoCapture cap(0);
	Mat frame;
	int i = 1;
	while (i <= number)
	{
		cap >> frame;
		imshow("frame", frame);
		string filename = format("H:/picture/pic%d.pgm", i);
		i++;
		imwrite(filename, frame);
		imshow("photo", frame);
		waitKey(500);
		destroyWindow("photo");
	}
	waitKey(1000);
}

//检测frame中的人脸和眼睛
//方框圈出
//圆圈圈出
//返回值为1为正确 0为出错
int detectAndDisplay(Mat frame)
{
	CascadeClassifier face_cascade;   //定义人脸分类器
	CascadeClassifier eyes_cascade;   //定义人眼分类器

	//-- 1. 加载.xml文件
	if (!face_cascade.load(face_cascade_name)) { printf("--(!)Error loading face cascade\n"); return 0; };
	if (!eyes_cascade.load(eyes_cascade_name)) { printf("--(!)Error loading eyes cascade\n"); return 0; };

	std::vector<Rect> faces;
	Mat frame_gray;

	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	equalizeHist(frame_gray, frame_gray);

	//图片演示
	//face_cascade.detectMultiScale(frame_gray, faces, 1.1, 3, 0, Size(180, 180), Size(220, 220));
	//视频演示
	face_cascade.detectMultiScale(frame_gray, faces, 1.1, 2, 0);
	for (size_t i = 0; i < faces.size(); i++)
	{
		//圆形框
		/*Point center(faces[i].x + faces[i].width / 2, faces[i].y + faces[i].height / 2);
		ellipse(frame, center, Size(faces[i].width / 2, faces[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);*/
		//矩形框
		rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);

		Mat faceROI = frame_gray(faces[i]);
		std::vector<Rect> eyes;

		//-- In each face, detect eyes
		eyes_cascade.detectMultiScale(faceROI, eyes, 1.1, 1, 0);

		for (size_t j = 0; j < eyes.size(); j++)
		{
			//矩形框
			Rect rect(faces[i].x + eyes[j].x, faces[i].y + eyes[j].y, eyes[j].width, eyes[j].height);
			rectangle(frame, rect, Scalar(0, 255, 0), 2, 8, 0);
			//圆形框
			/*Point eye_center(faces[i].x + eyes[j].x + eyes[j].width / 2, faces[i].y + eyes[j].y + eyes[j].height / 2);
			int radius = cvRound((eyes[j].width + eyes[j].height)*0.25);
			circle(frame, eye_center, radius, Scalar(255, 0, 0), 4, 8, 0);*/
		}
	}
	//显示窗口
	namedWindow(window_name, 2);
	imshow(window_name, frame);
	return 1;
}
//读取图片识别人脸
//通过摄像头识别人脸
//返回1为成功 返回0为失败
int PictureOrVidoe(void)
{
	int j = 0;
	//打开图片
	//Mat frame = imread(picture_name);

	//初始化摄像头
	VideoCapture capture;
	Mat frame;

	//-- 2. Read the video stream
	//打开摄像头
	capture.open(0);
	if (!capture.isOpened()) { printf("--(!)Error opening video capture\n"); return 0; }

	while (capture.read(frame))
	{
		if (frame.empty())
		{
			printf(" --(!) No captured frame -- Break!");
			break;
		}
		//调用函数
		j = detectAndDisplay(frame);
		waitKey(50);
	}
	return 1;
}
//拍照并进行加工处理
//转灰度 裁剪大小为92*112
int takephoto_2(void)
{
	CascadeClassifier cascada;
	cascada.load(haarcascade_frontalface_alt2);
	VideoCapture cap(0);
	Mat frame, myFace;
	int pic_num = 1;
	while (1) {
		//摄像头读图像
		cap >> frame;
		vector<Rect> faces;//vector容器存检测到的faces
		Mat frame_gray;
		cvtColor(frame, frame_gray, COLOR_BGR2GRAY);//转灰度化，减少运算
		cascada.detectMultiScale(frame_gray, faces, 1.1, 4, 0);
		printf("检测到人脸个数：%d\n", (int)faces.size());
		//1.frame_gray表示的是要检测的输入图像 2.faces表示检测到的人脸目标序列,3. 1.1表示每次图像尺寸减小的比例
		//4. 4表示每一个目标至少要被检测到3次才算是真的目标
		//(因为周围的像素和不同的窗口大小都可以检测到人脸表示每一个目标至少要被检测到3次才算是真的目标)
		//*5.flags–使用默认值0
		//识别到的脸用矩形圈出
		for (int i = 0; i < faces.size(); i++)
		{
			rectangle(frame, faces[i], Scalar(255, 0, 0), 2, 8, 0);
		}
		//当只有一个人脸时，开始拍照
		if (faces.size() == 1)
		{
			Mat faceROI = frame_gray(faces[0]);//在灰度图中将圈出的脸所在区域裁剪出
			//faces[0]即为检测到的唯一的人脸的矩阵
			//cout << faces[0].x << endl;//测试下face[0].x
			resize(faceROI, myFace, Size(92, 112));//将faceROI裁为92*112赋值给myFace
			putText(frame, to_string(pic_num), faces[0].tl(), 3, 1.2, (0, 0, 225), 2, 0);//在 faces[0].tl()的左上角上面写序号
			//string filename = format("H:/face_database/s%d/%d.pgm", NumberOfPeople, pic_num); //存放在文件夹以1-10.jpg 命名，format就是转为字符串
			string filename = format("Resources/face_database/s%d/%d.pgm", NumberOfPeople, pic_num);
			imwrite(filename, myFace);//存在当前目录下
			imshow(filename, myFace);//显示下size后的脸
			waitKey(500);//等待500us
			destroyWindow(filename);//:销毁指定的窗口
			pic_num++;//序号加1
			if (pic_num == 11)
			{
				break;//当序号为11时退出循环
			}
		}
		/*int c = waitKey(10);
		if ((char)c == 27) { break; } //10us内输入esc则退出循环
		imshow("frame", frame);//显示视频流
		waitKey(100);//等待100us*/

	}
	NumberOfPeople++;
	return 1;
}
/*
Mat norm_0_255(InputArray _src) {
	Mat src = _src.getMat();
	// 创建和返回一个归一化后的图像矩阵:  
	Mat dst;
	switch (src.channels()) {
	case 1:
		cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC1);//单通道
		break;
	case 3:
		cv::normalize(_src, dst, 0, 255, NORM_MINMAX, CV_8UC3);//三通道
		break;
	default:
		src.copyTo(dst);
		break;
	}
	return dst;
}
*/
//使用CSV文件去读图像和标签，主要使用stringstream和getline方法  
void read_csv(const string& filename, vector<Mat>& images, vector<int>& labels, char separator = ';') {
	std::ifstream file(filename.c_str(), ifstream::in);//c_str()函数可用可不用，无需返回一个标准C类型的字符串
	//检测文件是否打开
	if (!file)
	{
		string error_message = "No valid input file was given, please check the given filename.";
		CV_Error(CV_StsBadArg, error_message);
	}
	//line:整行读入
	//path:文件夹路径
	string line, path, classlabel;
	while (getline(file, line)) //从文本文件中读取一行字符，未指定限定符默认限定符为“/n”
	{
		stringstream liness(line);//这里采用stringstream主要作用是做字符串的分割
		getline(liness, path, separator);//读入图片文件路径以分好作为限定符
		getline(liness, classlabel);//读入图片标签，默认限定符
		if (!path.empty() && !classlabel.empty()) //如果读取成功，则将图片和对应标签压入对应容器中
		{
			images.push_back(imread(path, 0));
			labels.push_back(atoi(classlabel.c_str()));
		}
	}
}
//进行训练 生成xml文件
int TrainAndXml()
{
	//读取你的CSV文件路径.   
	//string fn_csv = "H:/face_database/at.txt";
	string fn_csv = "Resources/face_database/at.txt";

	// 2个容器来存放图像数据和对应的标签  
	vector<Mat> images;
	vector<int> labels;
	// 读取数据. 如果文件不合法就会出错  
	// 输入的文件名已经有了.  
	try
	{
		read_csv(fn_csv, images, labels); //从csv文件中批量读取训练数据
	}
	catch (cv::Exception & e)
	{
		cerr << "Error opening file \"" << fn_csv << "\". Reason: " << e.msg << endl;
		// 文件有问题，我们啥也做不了了，退出了  
		exit(1);
	}
	// 如果没有读取到足够图片，也退出.  
	if (images.size() <= 1) {
		string error_message = "This demo needs at least 2 images to work. Please add more images to your data set!";
		CV_Error(CV_StsError, error_message);
	}

	for (int i = 0; i < images.size(); i++)
	{
		if (images[i].size() != Size(92, 112))
		{
			cout << i << endl;
			cout << images[i].size() << endl;
		}
	}


	// 下面的几行代码仅仅是从你的数据集中移除最后一张图片，作为测试图片  
	//[gm:自然这里需要根据自己的需要修改，他这里简化了很多问题]  
	//Mat testSample = images[images.size() - 1];
	//string testLabel = labels[labels.size() - 1];
	//images.pop_back();//删除最后一张照片，此照片作为测试图片
	//labels.pop_back();//删除最有一张照片的labels
	// 下面几行创建了一个特征脸模型用于人脸识别，  
	// 通过CSV文件读取的图像和标签训练它。  
	//创建一个PCA人脸分类器，暂时命名为model吧，创建完成后
	//调用其中的成员函数train()来完成分类器的训练
	Ptr<BasicFaceRecognizer> model = EigenFaceRecognizer::create();
	model->train(images, labels);
	model->save("Resources/xml_file/PCA_train.xml");
	//model->save("H:/xml_file/PCA_train.xml");//保存路径可自己设置

	/*Ptr<BasicFaceRecognizer> model1 = FisherFaceRecognizer::create();
	model1->train(images, labels);
	model1->save("H:/xml_file/MyFaceFisherModel.xml");

	Ptr<LBPHFaceRecognizer> model2 = LBPHFaceRecognizer::create();
	model2->train(images, labels);
	model2->save("H:/xml_file/MyFaceLBPHModel.xml");*/

	// 下面对测试图像进行预测，predictedLabel是预测标签结果  
	//注意predict()入口参数必须为单通道灰度图像，如果图像类型不符，需要先进行转换
	//predict()函数返回一个整形变量作为识别标签
	/*int predictedLabel = model->predict(testSample);//加载分类器
	int predictedLabel1 = model1->predict(testSample);
	int predictedLabel2 = model2->predict(testSample);

	string result_message = format("Predicted class = %d / Actual class = %d.", predictedLabel, testLabel);
	string result_message1 = format("Predicted class = %d / Actual class = %d.", predictedLabel1, testLabel);
	string result_message2 = format("Predicted class = %d / Actual class = %d.", predictedLabel2, testLabel);
	cout << result_message << endl;
	cout << result_message1 << endl;
	cout << result_message2 << endl;*/
	return 1;
}
//识别图片
int Predict(Mat src_image)
{
	Mat face_test;
	int predict = 0;
	//截取的ROI人脸尺寸调整
	if (src_image.rows >= 120)
	{
		//改变图像大小，使用双线性差值
		resize(src_image, face_test, Size(92, 112));

	}
	//判断是否正确检测ROI
	if (!face_test.empty())
	{
		//测试图像应该是灰度图  
		predict = model->predict(face_test);
	}
	cout << predict << endl;
	return predict;
}
//人脸识别 返回1为正确 0为错误
/*int faceconregnizer()
{
	VideoCapture cap(0);    //打开默认摄像头  
	if (!cap.isOpened())
	{
		return 0;
	}
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
	model->read("H:/xml_file/MyFaceFisherModel.xml");
	// opencv2用read
	//3.利用摄像头采集人脸并识别
	while (1)
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
			if (pImage_roi[i].empty())
				continue;
			switch (Predict(pImage_roi[i])) //对每张脸都识别 接收Predict返回的值
			{
				//需要查询at.txt文件 确定label
			case 1:str = "wzh"; break;
			case 42:str = "dengwei"; break;
			case 43:str = "wangzhengliang"; break;
			default: str = "Sorry you are not in my database"; break;
			}
			Scalar color = Scalar(g_rng.uniform(0, 255), g_rng.uniform(0, 255), g_rng.uniform(0, 255));//所取的颜色任意值
			rectangle(frame, Point(faces[i].x, faces[i].y), Point(faces[i].x + faces[i].width, faces[i].y + faces[i].height), color, 1, 8);//放入缓存
			putText(frame, str, text_lb, FONT_HERSHEY_COMPLEX, 1, Scalar(0, 0, 255));//添加文字
		}

		delete[]pImage_roi;
		imshow("face", frame);
		waitKey(200);
	}

	return 1;
}
*/