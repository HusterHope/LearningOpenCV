#include <cv.h>
#include <highgui.h>

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
	cvNamedWindow("Example3", CV_WINDOW_AUTOSIZE);
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
			"Example3",//��������������
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
		cvShowImage("Example3", frame);
		//ÿ��30֡��ÿ֡ʱ��ԼΪ33ms
		//���ֿ��Ʒ������Ǻܾ�ȷ�����õķ����Ǵ�CvCapture�ṹ�ж�ȡ��
		char c = cvWaitKey(33);
		if (c == 27)
			break;
	}
	cvReleaseCapture(&g_capture);
	cvDestroyWindow("Example3");
	return(0);
}