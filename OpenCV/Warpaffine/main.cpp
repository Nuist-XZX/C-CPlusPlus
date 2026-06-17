#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/*
	仿射变换 = 线性变换（旋转、缩放、翻转、斜切）+ 平移
	void warpAffine(
		InputArray src,      // 输入图
		OutputArray dst,     // 输出图
		InputArray M,       // 2行3列仿射矩阵
		Size dsize,         // 输出图像尺寸
		int flags = INTER_LINEAR, // 插值
		int borderMode = BORDER_CONSTANT,
		const Scalar& borderValue = Scalar(0,0,0) // 边缘填充色
	);

	// 计算旋转缩放矩阵M
	Mat getRotationMatrix2D(
		Point2f center,  // 旋转中心点
		double angle,    // 角度：正数=逆时针，负数=顺时针
		double scale     // 缩放比例 1.0不变
	);

	// 计算放射变换矩阵M,通过原图的三个点和目标图的三个点自动计算出一个2×3的仿射变换矩阵M
	Mat getAffineTransform(
		const Point2f src[],  // 原图3个点数组
		const Point2f dst[]   // 目标对应3个点数组
	);
*/

int main() {
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);
	// 读取图像
	Mat src = imread("C:/Users/admin/Desktop/1.bmp", IMREAD_COLOR);

	// 1. 读图像中心点坐标
	Point2f center(src.cols / 2.0f, src.rows / 2.0f);
	// 2. 获取旋转矩阵：逆时针45度，缩放1倍
	Mat M = getRotationMatrix2D(center, 45, 1.0);
	// 3. 平移
	Mat M1 = (Mat_<double>(2, 3) << 1, 0, 80, 0, 1, 200);
	// 4. 翻转
	Mat M2 = (Mat_<double>(2, 3) << -1, 0, src.cols, 0, 1, 0); // 水平翻转
	Mat M3 = (Mat_<double>(2, 3) << 1, 0, 0, 0, -1, src.rows); // 上下翻转
	// 5. 斜切
	Mat M4 = (Mat_<double>(2, 3) << 1, 0.3, 0, 0, 1, 0); // 水平斜切
	Mat M5 = (Mat_<double>(2, 3) << 1, 0, 0, 0.2, 1, 0); // 垂直斜切
	// 6. 旋转+平移
	M.at<double>(0, 2) += 30;

	Mat img;
	warpAffine(src, img, M, src.size(), INTER_LINEAR, BORDER_CONSTANT, Scalar(0, 0, 0));


	namedWindow("img", WINDOW_FREERATIO);
	imshow("img", img);
	waitKey(0);
	destroyAllWindows();

	return 0;
}