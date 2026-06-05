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

	Mat grayimg, binaryimg, erodeimg, dilateimg, morpimg1, morpimg2, morpimg3, morpimg4;

	// 灰度 -> 二值化
	cvtColor(img, grayimg, COLOR_BGR2GRAY);
	threshold(grayimg, binaryimg, 127, 255, THRESH_BINARY);

	// 1、腐蚀
	erode(binaryimg, erodeimg, 5);

	// 2、膨胀
	dilate(binaryimg, dilateimg, 5);

	// 3、开运算
	Mat kernel = getStructuringElement(MORPH_RECT, Size(5,5)); // MORPH_RECT,即5*5内核中的元素全为1
	morphologyEx(binaryimg, morpimg1, MORPH_OPEN, kernel);

	// 4、闭运算
	morphologyEx(binaryimg, morpimg2, MORPH_CLOSE, 5);

	// 5、顶帽运算
	morphologyEx(binaryimg, morpimg3, MORPH_TOPHAT, 5);

	// 6、黑帽运算
	morphologyEx(binaryimg, morpimg4, MORPH_BLACKHAT, 5);

	namedWindow("img",WINDOW_FREERATIO);
	namedWindow("grayimg",WINDOW_FREERATIO);
	namedWindow("binaryimg",WINDOW_FREERATIO);
	namedWindow("erodeimg",WINDOW_FREERATIO);
	namedWindow("dilateimg",WINDOW_FREERATIO);
	namedWindow("morpimg1",WINDOW_FREERATIO);
	namedWindow("morpimg2",WINDOW_FREERATIO);
	namedWindow("morpimg3",WINDOW_FREERATIO);
	namedWindow("morpimg4",WINDOW_FREERATIO);

	imshow("img",img);
	imshow("grayimg", grayimg);
	imshow("binaryimg", binaryimg);
	imshow("erodeimg", erodeimg);
	imshow("dilateimg", dilateimg);
	imshow("morpimg1", morpimg1);
	imshow("morpimg2", morpimg2);
	imshow("morpimg3", morpimg3);
	imshow("morpimg4", morpimg4);

	waitKey(0);
	destroyAllWindows();

	return 0;
}