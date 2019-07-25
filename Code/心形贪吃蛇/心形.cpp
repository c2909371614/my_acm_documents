#include <stdio.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>
#include<queue>
#include<ctype.h>
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
int main() {
	char color1[7][20]={"color 0C","color 05","color 09","color 04","color 05","color 06","color 09"};
	int num=0;
	while(1){
		system(color1[num%7]);
		Hide();
		for(int i=1;i<=25;i++)
			putchar(' ');
		puts("曼曼,我爱你");
    	for (float y = 1.2f; y > -1.2f; y -= 0.1f) {
       	 	for (float x = -1.5f; x < 1.5f; x += 0.05f) {
           	 	float a = x * x + y * y - 1;
            	if(a * a * a - x * x * y * y * y <= 0.0f) printf("*");
				else printf(" ");
//            putchar(a * a * a - x * x * y * y * y <= 0.0f ? '*' : ' ');
       		}
        	Sleep(150);
        	putchar('\n');
    	}
    	num++;
	}
}
