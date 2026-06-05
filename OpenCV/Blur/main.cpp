#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

/*
	1、均值滤波		cv::blur(src, dst, cv::Size(3, 3));
	2、中值滤波		cv::medianBlur(src, dst, 5);  // 5x5的中值滤波
	3、高斯滤波		cv::GaussianBlur(src, dst, cv::Size(5, 5), 0);  // 5x5的高斯滤波
	4、双边滤波
*/

int main() {
	Mat img = imread("C:/Users/admin/Desktop/PCB.jpg",IMREAD_COLOR);
	if (img.empty()) {
		cout << "Could not find image file!" << endl;
		return -1;
	}

	Mat blurimg, mdblurimg, gausblurimg;

	// 1、均值滤波
	blur(img, blurimg, Size(3,3));

	// 2、中值滤波
	medianBlur(img, mdblurimg, 5);

	// 3、高斯滤波
	GaussianBlur(img, gausblurimg, Size(5,5), 0);

	namedWindow("blurimg",WINDOW_FREERATIO);
	namedWindow("mdblurimg",WINDOW_FREERATIO);
	namedWindow("gausblurimg",WINDOW_FREERATIO);

	imshow("blurimg", blurimg);
	imshow("mdblurimg", mdblurimg);
	imshow("gausblurimg", gausblurimg);

	waitKey(0);
	destroyAllWindows();

	return 0;
}