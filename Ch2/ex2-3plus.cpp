#include <cv.h>
#include <highgui.h>

//�ù���������Ƶ���Ŷ��ƶ�------

//������λ��
int g_slider_position = 0;
//"g_" ����ȫ�ֱ���(global)
CvCapture* g_capture = NULL;

void onTrackbarSlide(int pos)
{
	cvSetCaptureProperty(
		g_capture,
		CV_CAP_PROP_POS_FRAMES,
		//CV_CAP_PROP_POS_AVI_RATIO,
		pos
		);
}

int  main(int argc, char** argv)
{
	cvNamedWindow("Example3plus", CV_WINDOW_AUTOSIZE);
	g_capture = cvCreateFileCapture("test.avi");
	//��ȡ��Ƶ��֡��
	int frames = (int)cvGetCaptureProperty(
		g_capture,
		CV_CAP_PROP_FRAME_COUNT
		);
	if (frames != 0)
	{
		cvCreateTrackbar(
			"Position",//����������
			"Example3plus",//��������������
			&g_slider_position,
			frames,//���������ֵ
			onTrackbarSlide//�ص��������϶�������ʱ����
			);
	}
	IplImage* frame;
	while (1)
	{
		frame = cvQueryFrame(g_capture);
		if (!frame)
			break;
		cvShowImage("Example3plus", frame);

		//�ؼ�������cvSetTrackbarPos
		cvSetTrackbarPos(
			"Position",
			"Example3plus",
			g_slider_position
			);
		char c = cvWaitKey(33);
		//ÿ֡�����ù�����λ������
		g_slider_position++;
		if (c == 27)
			break;
	}
	cvReleaseCapture(&g_capture);
	cvDestroyWindow("Example3plus");
	return(0);
}