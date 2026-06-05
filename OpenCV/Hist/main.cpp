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

	// 灰度图
	Mat grayimg, calcimg; // 灰度图，直方图
	cvtColor(img, grayimg, COLOR_BGR2GRAY);

	// 获取直方图
	int histsize = 256;
	float ranges[] = {0, 256}; // 数组
	const float* histRanges = { ranges };
	/*
		void calcHist(
			const Mat* images,        // ① 图像数组指针
			int nimages,              // ② 数组里几张图，一般=1
			const int* channels,      // ③ 要统计的通道下标数组 灰度只有 0 通道；BGR 拆分后 B=0、G=1、R=2
			InputArray mask,          // ④ 掩码，Mat()=全图统计
			OutputArray hist,         // ⑤ 输出直方图，Mat(float)
			int dims,                 // ⑥ 直方图维度：灰度=1，彩色多维
			const int* histSize,      // ⑦ 每个维度bin数量，灰度常用{256}
			const float** ranges,     // ⑧ 像素取值范围 {0,256}
			bool uniform = true,      // ⑨ bin等宽
			bool accumulate = false   // ⑩ 是否累加多张图直方图
		);
	*/
	calcHist(&grayimg, 1, 0, Mat(), calcimg, 1, &histsize, &histRanges);

	// 创建直方图显示图像
	int hist_h = 300;	// 直方图高
	int hist_w = 500;	// 直方图宽
	Mat histImg(hist_h, hist_w, CV_8UC3, Scalar(0,0,0)); // 绘制直方图显示图像
	normalize(calcimg, calcimg, 0, hist_h, NORM_MINMAX);
	for (int i = 0; i < 256; i++)
	{
		line(histImg, Point(i, hist_h), Point(i, hist_h - cvRound(calcimg.at<float>(i))), Scalar(255, 255, 255));
	}

	// 直方图均衡化
	Mat equalimg, claheimg;
	equalizeHist(grayimg, equalimg);
	// 创建CLAHE自适应均衡器
	Ptr<CLAHE> clahe = createCLAHE(2.0, Size(8, 8));
	clahe->apply(grayimg, claheimg);


	namedWindow("histImg",WINDOW_FREERATIO);
	namedWindow("equalimg",WINDOW_FREERATIO);
	namedWindow("claheimg",WINDOW_FREERATIO);

	imshow("histImg", histImg);
	imshow("equalimg", equalimg);
	imshow("claheimg", claheimg);

	waitKey(0);
	destroyAllWindows();

	return 0;
}