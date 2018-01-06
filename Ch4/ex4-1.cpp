//ͨ����껭�����εļ�С����
#include <cv.h>
#include <highgui.h>

CvRect box;
bool drawing_box = false;

//����ص�����
void my_mouse_callback(int event, int x, int y, int flags, void* param);

//���ƾ���
void draw_box(IplImage* img, CvRect rect)
{
	cvRectangle(
		img,
		cvPoint(box.x, box.y),//���ϽǶ���
		cvPoint(box.x + box.width, box.y + box.height),//���½Ƕ���
		cvScalar(0xff, 0x00, 0x00)	//BGR��������ɫ
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
	//���ص�����ע�ᵽOpenCV��
	cvSetMouseCallback(
		"Box Example",
		my_mouse_callback,
		(void*)image	//���ӱ���
		);

	while (1)
	{
		//����
		cvCopyImage(image, temp);
		if (drawing_box)
			draw_box(temp, box);
		cvShowImage("Box Example",temp);
		//ÿ15msˢ��һ��ͼ�����Կ����϶����ʱ�ܿ�����΢�ӳ٣�
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
		//�ƶ����ʱ�����ƿ���״̬����Ϊ������������δ�С
		case CV_EVENT_MOUSEMOVE:
		{
			if (drawing_box)
			{
				box.width = x - box.x;
				box.height = y - box.y;
			}
		}
		break;
		//�����������������ƿ��ش�
		case CV_EVENT_LBUTTONDOWN:
		{
			drawing_box = true;
			box = cvRect(x, y, 0, 0);
		}
		break;
		//�ɿ���꣬�����ƿ��عرգ��������겢����ͼ��
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