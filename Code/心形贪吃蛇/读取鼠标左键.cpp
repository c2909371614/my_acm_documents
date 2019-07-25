
#include<iostream>
#include<windows.h>
 
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //必要的，我是背下来的 
 
using namespace std;
 
int main(){
	while(1){
		printf("鼠标左键是否按下：");
		if(KEY_DOWN(VK_LBUTTON))printf("是");
		else printf("否");
		printf("\n");
		
		printf("鼠标右键是否按下：");
		if(KEY_DOWN(VK_RBUTTON))printf("是");
		else printf("否");
		printf("\n");
		
		printf("鼠标滚轮键是否按下：");
		if(KEY_DOWN(VK_MBUTTON))printf("是");
		else printf("否");
		printf("\n");
		
		Sleep(20);//循环时间间隔，防止太占内存 
		system("cls");//清屏 
	}
 
	return 0;
}

