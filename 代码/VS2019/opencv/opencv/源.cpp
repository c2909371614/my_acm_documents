#include<iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>


using namespace cv;


int main()
{
	// ����һ��ͼƬ����Ϸԭ����
	Mat img = imread("F:\\�������ļ�\\acm\\����\\VS2019\\opencv\\opencvpic.jpg");
	// ����һ����Ϊ "��Ϸԭ��"����
	namedWindow("pic");
	// �ڴ�������ʾ��Ϸԭ��
	imshow("pic", img);
	// �ȴ�6000 ms�󴰿��Զ��ر�
	waitKey(6000);
}