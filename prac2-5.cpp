#include <cv.h>
#include <highgui.h>
#include <math.h>

//�ڶ�����ϰ��5�⡣

//������λ��
int g_scale = 1;


int  main(int argc, char** argv)
{
	CvCapture* capture = NULL;
	cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);
	capture = cvCreateFileCapture("test.avi");
	//��ȡ��Ƶ��֡��
	int frames = (int)cvGetCaptureProperty(
		capture,
		CV_CAP_PROP_FRAME_COUNT
		);
	if (frames != 0)
	{
		cvCreateTrackbar(
			"Scale",		//����������
			"Example3",		//��������������
			&g_scale,
			8,				//���������ֵ
			NULL	//�ص��������϶�������ʱ����
			);
	}
	IplImage* frame;
	IplImage* out;
	int i,count;
	while (1)
	{
		frame = cvQueryFrame(capture);
		if (!frame)
			break;
		if (g_scale >= 2)
		{
			//����cvPyrUp��cvPyrDownֻ�ܽ��зŴ����С2���Ĵ�������������ȷ�����Ŵ�����
			count = log(g_scale) / log(2);
			for (i = 0; i < count; i++)
			{
				out = cvCreateImage(
					cvSize(frame->width * 2, frame->height * 2),
					frame->depth,
					frame->nChannels
					);
				cvPyrUp(frame, out);
				frame = out;
			}
		}
		cvShowImage("Example3", frame);

		char c = cvWaitKey(33);

		if (c == 27)
			break;
	}
	cvReleaseCapture(&capture);
	cvDestroyWindow("Example3");
	return(0);
}