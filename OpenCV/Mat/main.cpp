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

	// 图像的长宽高
	int height = img.rows;			// 输入图像高度
	int width = img.cols;			// 宽
	int channels = img.channels();	// 通道数
	
	// Mat类创建图像
	// 创建空白图像
	// 第一种创建方法
	Mat pic1 = Mat(256,256,CV_8UC3);	// CV_8UC3=3通道，创建三通道，256*256的图像
	pic1 = Scalar(0,0,255);				// 使用Scalar为创建的空白图像赋颜色值，几个通道数赋几个值
	
	// 第二种创建方法
	Mat pic2 = Mat(Size(147,298),CV_8UC1);	// CV_8UC1 = 1通道，Size(col,row)固定图像尺寸
	pic2 = Scalar(0);
	
	// 第三种创建方法
	Mat pic3 = Mat::zeros(Size(158,800),CV_8UC3);	// Mat::zeros(),创建像素值全为0的图像
	
	// 第四种创建方法 - 创建与输入图像同类型、同宽同高的图像
	Mat pic4 = Mat(img.size(),img.type());	// img.size()得到图像尺寸，img.type()得到图像类型
	
	// 第五种方法(三个方式，直接赋值、copyTo、clone()) - 创建与输入图像相同的图像，即将输入图像赋值给创建的图像
	Mat pic5 = img;			// 这里并没有创建新图像，pic5本质上还是输入图像img，修改pic5相当于修改img
	// 假设我这里修改pic5,观察pic6和img是否有变化
	// pic5 = Scalar(0,0,255);
	
	Mat pic6 = img.clone();	
	
	Mat pic7;		
	img.copyTo(pic7);		// 这里是创建了一个新图像pic6，并且把img复制到了pic6，修改pic6不会改变原图img
	
	
	int pic_height = pic6.rows;
	int pic_width = pic6.cols;
	int pic_channels = pic6.channels();
	printf("%d %d %d\n", pic_height, pic_width, pic_channels);
	
	
	namedWindow("input",WINDOW_FREERATIO);
	imshow("input",pic6);
	waitKey(0);

	return 0;
}