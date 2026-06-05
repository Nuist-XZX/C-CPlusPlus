#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);

	Mat img = imread("C:/Users/admin/Desktop/PCB.jpg",IMREAD_COLOR);
	if (img.empty()) {
		cout << "Could not find image file!" << endl;
		return -1;
	}

	// 灰度-二值化
	Mat grayimg, binaryimg;
	cvtColor(img, grayimg, COLOR_BGR2GRAY);
	threshold(grayimg, binaryimg, 100, 255, THRESH_BINARY);

	// 轮廓检测
	// 1、找到图像中轮廓
	vector<vector<Point>>contours; // 轮廓
	vector<Vec4i>hierarchy;	// 存放轮廓结构变量
	findContours(binaryimg, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
	// 输出轮廓结构描述
	//for (size_t i = 0; i < hierarchy.size(); i++) {
	//	cout << hierarchy[i] << endl; // [5813, 5811, -1, 5020]
	//}

	// 2、绘制轮廓
	//for (size_t t = 0; t < contours.size(); t++) {
	//	drawContours(img, contours, t, Scalar(0, 0, 255), 1, 8);
	//}
	drawContours(img, contours, -1, Scalar(0,0,255), 1, 8, hierarchy);

	// 3、计算轮廓面积和周长
	for (size_t t = 0; t < contours.size(); t++) {
		double area = contourArea(contours[t]);
		double length = arcLength(contours[t],true);
		cout << area << "和" << length << endl;
	}
	
	// 4、计算轮廓最大/最小外接矩形
	// 对二值化图像进行膨胀，填充缝隙
	Mat dilateimg;
	dilate(binaryimg, dilateimg, 5);
	// 边缘检测
	Canny(dilateimg, dilateimg, 100, 200, 3);


	namedWindow("dilateimg",WINDOW_FREERATIO);
	imshow("dilateimg", dilateimg);
	waitKey(0);
	destroyAllWindows();

	return 0;
}