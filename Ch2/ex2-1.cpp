#include <highgui.h>

int main(int argc, char** argv)
{
	IplImage* img = cvLoadImage("lena.jpg",1);
	//也可以使用如下形式：（需要在 项目-属性-配置属性-调试-命令参数 中填写图片位置）
	//IplImage* img = cvLoadImage(argv[1]);
	
	//指定窗口标题和大小
	//CV_WINDOW_AUTOSIZE 表示让窗口大小适应原始图片
	cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
	cvShowImage("Example1", img);
	//等待用户按键
	//正数为指定毫秒数，负数或0为无限等待
	cvWaitKey(0);
	//理论上在应用程序结束时相应资源会由操作系统自动释放
	//但是养成习惯，在程序中显式释放是有好处的
	cvReleaseImage(&img);
	cvDestroyWindow("Example1");
}