#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	Mat img = imread("C:/Users/admin/Desktop/1.bmp",IMREAD_COLOR);
	if (img.empty()) {
		cout << "Could not find image file!" << endl;
		return -1;
	}

	int height = img.rows;
	int width = img.cols;
	int channels = img.channels();
	// 遍历访问每个像素值 img.at<Vec3b>(y,x) 访问(x,y)处的像素值
	for(int i = 0;i < height; i++){
		for(int j = 0;j< width;j++){
			Vec3b pixel = img.at<Vec3b>(i,j);
			int blue = pixel[0];
			int green = pixel[1];
			int red = pixel[2];
			
			// 对像素进行修改
			// img.at<Vec3b>(i,j)[0] = 255 - blue;
			// img.at<Vec3b>(i,j)[1] = 255 - green;
			// img.at<Vec3b>(i,j)[2] = 255 - red;
			// 上述等价于
			pixel[0] = 255 - pixel[0];
			pixel[1] = 255 - pixel[1];
			pixel[2] = 255 - pixel[2];
			img.at<Vec3b>(i,j) = pixel;  // 关键：必须赋值回图像！
		}
	}
	
	namedWindow("input",WINDOW_FREERATIO);
	imshow("input",img);
	waitKey(0);

	return 0;
}