#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

/* 
	旋转
	rotate(src,dst,rotateCode)
	rotateCode: ROTATE_90_CLOCKWISE 顺时针90
				ROTATE_180 旋转180
				ROTATE_270_CLOCKWISE 顺时针270（即逆时针90）
*/

int main(){
	utils::logging::setLogLevel(utils::logging::LOG_LEVEL_SILENT);
	// 读取图像
	Mat src = imread("C:/Users/admin/Desktop/1.bmp",IMREAD_COLOR);
	Mat img;
	rotate(src,img,ROTATE_90_CLOCKWISE);
	
	
	namedWindow("img",WINDOW_FREERATIO);
	imshow("img",img);
	
	waitKey(0);
	destroyAllWindows();
	
	
	return 0;
}
