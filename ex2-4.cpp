#include <cv.h>
#include <highgui.h>

//������ͼ����ƽ�������������ڷֱ���ʾƽ��ǰ���ͼ��
void example2_4(IplImage* image)
{
	//����չʾ���������Ĵ���
	cvNamedWindow("Example4-in");
	cvNamedWindow("Example4-out");

	cvShowImage("Example4-in", image);

	//����ͼ��ṹ�ռ������洢ƽ��������ͼ��
	IplImage* out = cvCreateImage(
		cvGetSize(image),		//cvSize�ṹ
		IPL_DEPTH_8U,			//ÿ�����ص���������
		3						//ͨ������
		);

	//ƽ������
	cvSmooth(image, out, CV_GAUSSIAN, 3, 3);
	//�������������ʾƽ�����ͼ��
	cvShowImage("Example4-out", out);
	cvReleaseImage(&out);
}

int  main(int argc, char** argv)
{
	//CvCapture �����������������Ƶ�ļ���ص���Ϣ
	CvCapture* capture = cvCreateFileCapture("test.avi");
	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame)
			break;
		example2_4(frame);
		//ÿ��30֡��ÿ֡ʱ��ԼΪ33ms
		//���ֿ��Ʒ������Ǻܾ�ȷ�����õķ����Ǵ�CvCapture�ṹ�ж�ȡ��
		char c = cvWaitKey(33);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&capture);
	cvDestroyAllWindows();
}