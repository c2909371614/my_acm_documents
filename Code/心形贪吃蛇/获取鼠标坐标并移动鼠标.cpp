
//#include "stdafx.h"
#include "stdio.h"
#include <iostream>
#include<windows.h>
#include<time.h>
#include <string>
using namespace std;
 
int getNewValue(int last){
//	while(true){
//		int newValue = rand()%300 + 300;
//		if(abs(newValue-last) > 50){
//			return newValue;//
//		}
//	}
	return (rand()%3-1)!=0?(rand()%3-1)*50:(rand()%3-1)*50;
}
 
int main(){
	cout<<"控制鼠标移动的程序已经开始运行^_^"<<endl;
	//HWND hwnd=GFetoregroundWindow();
	//ShowWindow(hwnd,SW_HIDE); //将cmd窗口隐藏起来，让程序在后台运行
    POINT p;
	POINT last_p;
    while(true){
		GetCursorPos(&last_p);//获取鼠标坐标
 
		Sleep(1000 );
 
        GetCursorPos(&p);//获取鼠标坐标
		//日志记录
		time_t timePointer;
		time(&timePointer);
		char temp[64];
		strftime(temp,sizeof(temp),"%Y-%m-%d %H:%M:%S",localtime(&timePointer));
		cout<<(string)temp<<" ";
		if(p.x == last_p.x && p.y == last_p.y){
			SetCursorPos(getNewValue(p.x),getNewValue(p.y));//更改鼠标坐标
 
			POINT tempPoint;
			GetCursorPos(&tempPoint);
			printf("no move,change position to:%d,%d\n",tempPoint.x,tempPoint.y);
		}else{
			printf("moved,do nothing.\n");
		}
    } 
    return 0;
}

