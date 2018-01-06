//AlphaÈÚºÏ
#include <cv.h>
#include <highgui.h>

int main(int argc, char** argv)
{
	IplImage* src1 = cvLoadImage("lena.jpg", 1);
	IplImage* src2 = cvLoadImage("faceScene.jpg", 1);
	int x = 100;
	int y = 100;
	int width = 240;
	int height = 300;
	double alpha = 0.3;
	double beta = 0.7;
	cvSetImageROI(src1, cvRect(x, y, width, height));
	cvSetImageROI(src2, cvRect(0, 0, width, height));
	cvAddWeighted(src1, alpha, src2, beta, 0.0, src1);
	cvResetImageROI(src1);
	cvNamedWindow("Alpha_blend", 1);
	cvShowImage("Alpha_blend", src1);
	cvWaitKey(0);
}