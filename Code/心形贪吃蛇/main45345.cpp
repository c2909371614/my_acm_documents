#include "graphics.h"   //����ͷ�ļ�
 
 
int main(){
	initgraph(640,480);     //��ʼ����ͼ����
	
	outtextxy(100,300,"Alohe world!");  //���һ����
	line(10,10,400,400);     //��һ��ֱ�ߣ���(10,10)��(400,400)��
	
	ege::getch();       //����������
	closegraph();
	return 0;
}

