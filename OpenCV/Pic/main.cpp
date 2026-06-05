/* 
	opencv学习-2026/05/15
	内容：imread、imshow、imwrite、namedWindow、destroyWindow(winname)
		1、imread:
			IMREAD_COLOR-BGR通道的彩色图像
			IMREAD_GRAYSCALE-灰色图像
			IMREAD_ANYCOLOR
			IMREAD_UNCHANGED:如果加载并保存的图片是带有透明通道的，即4通道的，需要在加载时用这个参数，表示不改变加载图片的通道数
		2、imshow:imshow("窗口名称",要显示的图片)
			先namedWindow创建窗口，再使用imshow将图片投放在窗口上
			
		3、imwrite:imwrite("地址",要保存的图片)
			
		4、namedWindow:namedWindow("窗口名字",窗口大小设置)
			WINDOW_AUTOSIZE:窗口自动大小不可拉伸、WINDOW_FREERATIO:窗口自适应大小可拉伸、WINDOW_NORMAL:可拉伸

		5、destroyALLWindows(要销毁的窗口名称)
*/

#include<iostream>
#include<opencv2/opencv.hpp>
using namespace std;
using namespace cv;

int main() {
	// imread()参数: IMREAD_COLOR-BGR通道的彩色图像、IMREAD_GRAYSCALE-灰色图像、 IMREAD_ANYCOLOR
	// Mat img = imread("C:/Software/opencv/sources/samples/data/opencv-logo.png", IMREAD_UNCHANGED); // 4通道图片
	Mat img = imread("C:/Users/admin/Desktop/1.bmp", IMREAD_COLOR);
	if(img.empty()){
		cout << "Could not find image file!\n" << endl;
		return -1;
	}
	
	// 打印图像基本属性 - 长宽、通道、某点像素值
	int height = img.rows;
	int width = img.cols;
	int channels = img.channels();
	int depth = img.depth();
	int typ = img.type(); // 16，表示枚举类型是16
	//CV_8UC3 表示 8位的unsigned char无符号 3通道 3*8=24位深  像素值范围0-255
	if(typ == CV_8UC3){
		cout << height << endl;	//cout<< << endl;自带\n
		printf("typ: %d depth: %d width: %d channels: %d\n",typ,depth,width,channels);
	}	
	
	//WINDOW_AUTOSIZE:窗口自动大小不可拉伸、WINDOW_FREERATIO:窗口自适应大小可拉伸、WINDOW_NORMAL:可拉伸
	namedWindow("input", WINDOW_FREERATIO);
	imshow("input",img);
	// imwrite("C:/Users/admin/Desktop/test.png",img); // 保存
	waitKey(0);
	destroyAllWindows(); // 销毁所有窗口
	


	return 0;
}