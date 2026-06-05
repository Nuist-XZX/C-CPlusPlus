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

	Mat grayimg, sobelximg, sobelyimg, cannyimg, laplacianimg;
	// 灰度
	cvtColor(img, grayimg, COLOR_BGR2GRAY);

	// Canny
	// Canny 四步流水线：高斯模糊(5*5高斯核) → Sobel 求梯度 → 非极大值抑制 → 双阈值滞后筛选
	Canny(grayimg, cannyimg, 100, 200);

	// Sobel
	Sobel(grayimg, sobelximg, CV_16S, 1, 0, 5); // 水平方向梯度 CV_16S 是16位有符号短整型
	Sobel(grayimg, sobelyimg, CV_16S, 0, 1, 9); // 垂直方向梯度
	Mat absgx, absgy, sobelimg;
	/*
		void convertScaleAbs(
			InputArray src,        // 输入图像
			OutputArray dst,       // 输出uint8图像
			double alpha = 1.0,    // 缩放系数
			double beta = 0.0      // 偏移量
		); // dst(x,y)=|src(x,y) * alpha + beta|
	*/
	convertScaleAbs(sobelximg, absgx); // 取绝对值 + 转换为uint8  
	convertScaleAbs(sobelyimg, absgy);
	addWeighted(absgx, 0.5, absgy, 0.5, 0, sobelimg); // 0.5*absgx + 0.5*absgy + 0 代替开根号

	// Laplacian - 使用前先进行高斯降噪
	Laplacian(grayimg, laplacianimg, CV_16S, 3);
	convertScaleAbs(laplacianimg, laplacianimg);

	namedWindow("cannyimg",WINDOW_FREERATIO);
	namedWindow("sobelximg",WINDOW_FREERATIO);
	namedWindow("sobelyimg",WINDOW_FREERATIO);
	namedWindow("sobelimg",WINDOW_FREERATIO);
	namedWindow("laplacianimg",WINDOW_FREERATIO);

	imshow("cannyimg", cannyimg);
	imshow("sobelximg", sobelximg);
	imshow("sobelyimg", sobelyimg);
	imshow("sobelimg", sobelimg);
	imshow("laplacianimg", laplacianimg);

	waitKey(0);
	destroyAllWindows();

	return 0;
}