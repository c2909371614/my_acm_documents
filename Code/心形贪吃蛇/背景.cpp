/* 0 = ��ɫ   1 = ��ɫ   2 = ��ɫ 3 = ����ɫ  4 = ��ɫ               
 5 = ��ɫ  6 = ��ɫ 7 = ��ɫ 8 = ��ɫ  9 = ����ɫ  A = ����ɫ     
  B = ��ǳ��ɫ   C = ����ɫ    D = ����ɫ     
	  E = ����ɫ         F = ����ɫ*/
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
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ  
	CursorInfo.bVisible = false; //���ؿ���̨���  
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬   
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
