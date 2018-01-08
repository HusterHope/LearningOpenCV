//2-a实现较容易，略去
#include <highgui.h>
#include <cv.h>
#include <string.h>

using namespace std;

bool flag = false;

void color_mouse_cb(int event, int x, int y, int flags, void* param);

void show_color(IplImage* img, CvPoint point)
{

}

int main()
{
	IplImage* img = cvLoadImage("lena.jpg", 1);
	IplImage* show = cvCloneImage(img);
	IplImage* temp = cvCloneImage(img);
	cvNamedWindow("Prac4-2", CV_WINDOW_AUTOSIZE);
	cvSetMouseCallback("Prac4-2", color_mouse_cb, (void*)temp);

	while (1)
	{
		//每次点击后，将本次信息输出，并清除上一次的文字
		if (flag)
		{
			cvCopyImage(temp, show);
			cvCopyImage(img, temp);
			flag = false;
		}
		
		cvShowImage("Prac4-2", show);
		if (cvWaitKey(15) == 27)
			break;
	}

	cvReleaseImage(&img);
	cvReleaseImage(&show);
	cvReleaseImage(&temp);
	cvDestroyAllWindows();
}

void color_mouse_cb(int event, int x, int y, int flags, void* param)
{
	
	if (event == CV_EVENT_LBUTTONDOWN)
	{
		flag = true;
		CvFont text;
		CvFont* tp = &text;
		cvInitFont(tp, CV_FONT_HERSHEY_COMPLEX, 1.0, 1.0);
		IplImage* image = (IplImage*)param;
		uchar* ptr = (uchar*)(image->imageData + y*image->widthStep);
		//获取对应点颜色信息，将待输出的字符串拼接
		string s = "B:" + to_string(ptr[3 * x]) + " G:" + to_string(ptr[3 * x + 1]) + " R:" + to_string(ptr[3 * x + 2]);
		char* color = (char*)s.c_str();
		cvPutText(image, color, cvPoint(x, y), tp, cvScalar(0, 0, 255));
	}
	
}