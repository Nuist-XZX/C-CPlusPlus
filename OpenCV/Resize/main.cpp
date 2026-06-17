#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 
	图像缩放
	resize(src,dst,dsize,fx,fy,interpolation)
	
	dsize:目标缩放图像的大小(1280,720),如果定义了dsize则不需要fx/fy,如果设置了fx/fy则不需要dsize
	fx:x轴的缩放因子
	fy:y轴的缩放因子
	interpolation:插值算法
		INTER_NEARSET:邻近插值,速度快,效果差
		INTER_LINEAR:双线性插值,原图中的4个点
		INTER_CUBIC:三次插值,原图中的16个点
		INTER_AREA:效果最好,速度最慢
	
*/

int main(){
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);
	// 读取图像
	Mat src = imread("C:/Users/admin/Desktop/1.bmp",IMREAD_COLOR);
	Mat resize_img;
	resize(src,resize_img,Size(100,400));
	
	namedWindow("Pic1",WINDOW_FREERATIO);
	namedWindow("Pic2",WINDOW_FREERATIO);
	imshow("Pic1",src);
	imshow("Pic2",resize_img);
	waitKey(0);
	destroyAllWindows();
	
	return 0;
}