#include <highgui.h>
#include <cv.h>

int  main(int argc, char** argv)
{
	cvNamedWindow("Prac4-1-bc", CV_WINDOW_AUTOSIZE);

	CvCapture* capture = cvCreateFileCapture("test.avi");
	if (capture == NULL)
		return -1;
	IplImage *f;

	//��ȡÿ��֡��
	int fps = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
	//ÿ֡����ʱ��
	double t = 1000.0 / fps;
	int fw = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH);
	int fh = (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT);
	//���ⴴ����grayc��cannyc���ڴ洢ת��Ϊ3ͨ���ĻҶ�ͼ
	IplImage* grayf = cvCreateImage(cvSize(fw, fh), 8, 1);
	IplImage* grayc = cvCreateImage(cvSize(fw, fh), 8, 3);
	IplImage* cannyf = cvCreateImage(cvSize(fw, fh), 8, 1);
	IplImage* cannyc = cvCreateImage(cvSize(fw, fh), 8, 3);
	//����һ���µ�ͼ����߶���ԭʼͼ����ͬ�����Ϊԭ����Ƶ֡��3��
	IplImage* wholef = cvCreateImage(cvSize(3 * fw, fh), 8, 3);
	//����3��ͼ��ͷ
	IplImage* sub_img1 = cvCreateImageHeader(cvSize(fw, fh), 8, 3);
	IplImage* sub_img2 = cvCreateImageHeader(cvSize(fw, fh), 8, 3);
	IplImage* sub_img3 = cvCreateImageHeader(cvSize(fw, fh), 8, 3);

	sub_img1->origin = wholef->origin;
	sub_img1->widthStep = wholef->widthStep;
	sub_img2->origin = wholef->origin;
	sub_img2->widthStep = wholef->widthStep;
	sub_img3->origin = wholef->origin;
	sub_img3->widthStep = wholef->widthStep;
	CvFont text;
	CvFont* tp = &text;
	cvInitFont(tp, CV_FONT_HERSHEY_COMPLEX, 1.0, 1.0);
	while (1)
	{
		f = cvQueryFrame(capture);
		if (!f)
			break;
		//����ͼ��ͷ�ֱ�ָ��ͼ�����ݵĿ�ʼ����1/3����2/3��
		sub_img1->imageData = wholef->imageData;
		sub_img2->imageData = wholef->imageData + fw*wholef->nChannels;
		sub_img3->imageData = wholef->imageData + 2 * fw*wholef->nChannels;
		cvCvtColor(f, grayf, CV_BGR2GRAY);
		cvCanny(f, cannyf, 10, 100, 3);
		cvCvtColor(grayf, grayc,CV_GRAY2BGR);
		cvCvtColor(cannyf, cannyc, CV_GRAY2BGR);
		//ʹ��cvCopy����
		cvCopy(f, sub_img1);
		cvCopy(grayc, sub_img2);
		cvCopy(cannyc, sub_img3);
		//��ͼ��������ͬ����д�Ϻ��ʵı�ǩ
		cvPutText(wholef, "original", cvPoint(0, 20), tp, cvScalar(0,0,255));
		cvPutText(wholef, "gray", cvPoint(fw, 20), tp, cvScalar(0, 0, 255));
		cvPutText(wholef, "canny", cvPoint(fw*2, 20), tp, cvScalar(0, 0, 255));
		cvShowImage("Prac4-1-bc", wholef);

		char c = cvWaitKey(t);
		if (c == 27)
			break;
		
	}
	cvReleaseCapture(&capture);
	cvDestroyAllWindows();
}