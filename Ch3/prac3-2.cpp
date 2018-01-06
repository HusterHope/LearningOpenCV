#include <cv.h>
#include <highgui.h>

int main()
{
	CvMat* mat = cvCreateMat(200, 200, CV_8UC3);
	cvZero(mat);
	cvCircle(mat, cvPoint(50, 50), 20, cvScalar(100, 100, 100), 1, 8, 0);
	cvNamedWindow("Prac3-2", CV_WINDOW_AUTOSIZE);
	cvShowImage("Prac3-2", mat);
	cvWaitKey(0);
	return 0;
}