#include <highgui.h>

int  main(int argc, char** argv)
{
	cvNamedWindow("Example2", CV_WINDOW_AUTOSIZE);
	//CvCapture �����������������Ƶ�ļ���ص���Ϣ
	CvCapture* capture = cvCreateFileCapture("test.avi");
	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame)
			break;
		cvShowImage("Example2", frame);
		//ÿ��30֡��ÿ֡ʱ��ԼΪ33ms
		//���ֿ��Ʒ������Ǻܾ�ȷ�����õķ����Ǵ�CvCapture�ṹ�ж�ȡ��
		char c = cvWaitKey(33);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example2");
}