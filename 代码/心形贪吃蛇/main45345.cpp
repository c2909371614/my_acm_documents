#include "graphics.h"   //引入头文件
 
 
int main(){
	initgraph(640,480);     //初始化绘图区域
	
	outtextxy(100,300,"Alohe world!");  //输出一行字
	line(10,10,400,400);     //画一条直线，从(10,10)到(400,400)点
	
	ege::getch();       //其余清理工作
	closegraph();
	return 0;
}

