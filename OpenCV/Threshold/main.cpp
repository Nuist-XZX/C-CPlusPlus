#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

/*
	1、简单阈值		cv::threshold(src, dst, 127, 255, cv::THRESH_BINARY);
	2、自适应阈值	cv::adaptiveThreshold(src, dst, 255, cv::ADAPTIVE_THRESH_MEAN_C, cv::THRESH_BINARY, 11, 2);
	3、OSTU阈值		cv::threshold(src, dst, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
*/

int main() {
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT); // 隐藏opencv警告

	Mat img = imread("C:/Users/admin/Desktop/PCB.jpg",IMREAD_COLOR);
	if (img.empty()) {
		cout << "Could not find image file!" << endl;
		return -1;
	}

	// 转为灰度图像
	Mat grayimg, binaryimg1, binaryimg2, binaryimg3, binaryimg4, binaryimg5, binaryimg6, binaryimg7, binaryimg8;
	cvtColor(img, grayimg, COLOR_BGR2GRAY);

	// 1、简单阈值
	threshold(grayimg, binaryimg1, 127, 255, THRESH_BINARY);		// 大于阈值置255，否则0
	threshold(grayimg, binaryimg2, 127, 255, THRESH_BINARY_INV);	// 大于阈值置0，否则255
	threshold(grayimg, binaryimg3, 127, 255, THRESH_TRUNC);			// 大于阈值置127，否则不变
	threshold(grayimg, binaryimg4, 127, 255, THRESH_TOZERO);		// 大于阈值保持不变，否则0
	threshold(grayimg, binaryimg5, 127, 255, THRESH_TOZERO_INV);	// 大于阈值置0，否则保持不变

	// 2、自适应阈值
	adaptiveThreshold(grayimg, binaryimg6, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 5, 122);
	adaptiveThreshold(grayimg, binaryimg7, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 5, 10);

	// 3、OSTU
	threshold(grayimg, binaryimg8, 0, 255, cv::THRESH_BINARY | cv::THRESH_OTSU);
	
	// 窗口
	namedWindow("img",WINDOW_FREERATIO);
	namedWindow("grayimg",WINDOW_FREERATIO);
	namedWindow("binaryimg1",WINDOW_FREERATIO);
	namedWindow("binaryimg2",WINDOW_FREERATIO);
	namedWindow("binaryimg3",WINDOW_FREERATIO);
	namedWindow("binaryimg4",WINDOW_FREERATIO);
	namedWindow("binaryimg5",WINDOW_FREERATIO);
	namedWindow("binaryimg6",WINDOW_FREERATIO);
	namedWindow("binaryimg7",WINDOW_FREERATIO);
	namedWindow("binaryimg8",WINDOW_FREERATIO);

	// 展示
	imshow("img", img);
	imshow("grayimg", grayimg);
	imshow("binaryimg1", binaryimg1);
	imshow("binaryimg2", binaryimg2);
	imshow("binaryimg3", binaryimg2);
	imshow("binaryimg4", binaryimg2);
	imshow("binaryimg5", binaryimg5);
	imshow("binaryimg6", binaryimg6);
	imshow("binaryimg7", binaryimg7);
	imshow("binaryimg8", binaryimg8);

	waitKey(0);
	destroyAllWindows();

	return 0;
}