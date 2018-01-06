//通过鼠标画正方形的简单小程序
#include <cv.h>
#include <highgui.h>

CvRect box;
bool drawing_box = false;

//定义回调函数
void my_mouse_callback(int event, int x, int y, int flags, void* param);

//绘制矩形
void draw_box(IplImage* img, CvRect rect)
{
	cvRectangle(
		img,
		cvPoint(box.x, box.y),//左上角顶点
		cvPoint(box.x + box.width, box.y + box.height),//右下角顶点
		cvScalar(0xff, 0x00, 0x00)	//BGR，画出蓝色
		);
}

int main()
{
	box = cvRect(-1, -1, 0, 0);
	IplImage* image = cvCreateImage(
		cvSize(200, 200),
		IPL_DEPTH_8U,
		3
		);
	cvZero(image);
	IplImage* temp = cvCloneImage(image);

	cvNamedWindow("Box Example");
	//将回调函数注册到OpenCV中
	cvSetMouseCallback(
		"Box Example",
		my_mouse_callback,
		(void*)image	//附加变量
		);

	while (1)
	{
		//软拷贝
		cvCopyImage(image, temp);
		if (drawing_box)
			draw_box(temp, box);
		cvShowImage("Box Example",temp);
		//每15ms刷新一次图像（所以快速拖动鼠标时能看到轻微延迟）
		if (cvWaitKey(15) == 27)
			break;
	}

	cvReleaseImage(&image);
	cvReleaseImage(&temp);
	cvDestroyAllWindows();
}

void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
	IplImage* image = (IplImage*)param;

	switch (event)
	{
		//移动鼠标时检查绘制开关状态，若为开启则调整矩形大小
		case CV_EVENT_MOUSEMOVE:
		{
			if (drawing_box)
			{
				box.width = x - box.x;
				box.height = y - box.y;
			}
		}
		break;
		//按下鼠标左键：将绘制开关打开
		case CV_EVENT_LBUTTONDOWN:
		{
			drawing_box = true;
			box = cvRect(x, y, 0, 0);
		}
		break;
		//松开鼠标，将绘制开关关闭，调整坐标并绘制图像。
		case CV_EVENT_LBUTTONUP:
		{
			drawing_box = false;
			if (box.width < 0)
			{
				box.x += box.width;
				box.width *= -1;
			}
			if (box.height < 0)
			{
				box.y += box.height;
				box.height *= -1;
			}
			draw_box(image, box);
		}
		break;
	}
}