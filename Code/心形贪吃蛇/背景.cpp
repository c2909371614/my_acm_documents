/* 0 = 黑色   1 = 蓝色   2 = 绿色 3 = 湖蓝色  4 = 红色               
 5 = 紫色  6 = 黄色 7 = 白色 8 = 灰色  9 = 淡蓝色  A = 淡绿色     
  B = 淡浅绿色   C = 淡红色    D = 淡紫色     
	  E = 淡黄色         F = 亮白色*/
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
void position(int x,int y) {
	COORD pos={x,y};
	HANDLE Out=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(Out,pos);
}
void Hide() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  
	CONSOLE_CURSOR_INFO CursorInfo;  
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息  
	CursorInfo.bVisible = false; //隐藏控制台光标  
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态   
}
int main()
{
	
	char color1[7][20]={"color 01","color 02","color 03","color 04","color 05","color 06","color 07"};
	Hide();
	for(int i=0;;i++){
		position(0,0);
		system(color1[i%7]);
		puts("helloworld!"); 
		
		Sleep(1000);
	}
	
}
