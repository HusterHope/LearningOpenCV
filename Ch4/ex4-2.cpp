#include <stdio.h>
#include <highgui.h>

//开关变量
int g_switch_value = 0;

void switch_off_function()
{

}

void switch_on_function()
{
	//加入一个小功能：点击一次开关就在控制台上输出一条语句。
	printf("Switch On!\n");
}
//回调函数
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