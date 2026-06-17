#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 
	翻转
	flip(src,dst,flipCode)
	flipCode: 0上下翻转
			  >0常用1，左右翻转
			  <0常用-1，上下+左右同时翻转，即旋转180度效果
*/

int main(){
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);
	// 读取图像
	Mat src = imread("C:/Users/admin/Desktop/1.bmp",IMREAD_COLOR);
	Mat img;
	flip(src,img,-1);
	
	namedWindow("pic",WINDOW_FREERATIO);
	imshow("pic",img);
	waitKey(0);
	destroyAllWindows();
	
	return 0;
}