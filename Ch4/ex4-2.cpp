#include <stdio.h>
#include <highgui.h>

//���ر���
int g_switch_value = 0;

void switch_off_function()
{

}

void switch_on_function()
{
	//����һ��С���ܣ����һ�ο��ؾ��ڿ���̨�����һ����䡣
	printf("Switch On!\n");
}
//�ص�����
void switch_callback(int position)
{
	if (position == 0)
		switch_off_function();
	else
		switch_on_function();
}

int main()
{
	cvNamedWindow("Demo Window", 1);
	cvCreateTrackbar(
		"Switch",
		"Demo Window",
		&g_switch_value,
		1,
		switch_callback
		);
	while (1)
	{
		if (cvWaitKey(15) == 27)
			break;
		cvSetTrackbarPos("Switch","Demo Window",0);
	}
}