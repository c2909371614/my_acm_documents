#include<iostream>
#include<windows.h>
#include<winuser.h>
#include<bits/stdc++.h>
using namespace std;
int MIN = 3600;
struct QQ {
	int x,y;
	QQ(int X,int Y) {
		x = X;
		y = Y;
	}
};
QQ q(922,467), q1(1035,552);

int main() {
	fstream out("click_pos.txt",ios::out|ios::app);
	while(true)

	{
		Sleep(3);//µ»3√Î∆Ù∂Ø
		POINT P;
		GetCursorPos(&P);
		int x1=P.x;
		int y1=P.y;
		out << x1 << " " << y1 << endl;
		cout << x1 << " " << y1 << endl;
		Sleep(1000);
//		mouse_event(MOUSEEVENTF_LEFTDOWN,q.x,q.y,0,0);
//		mouse_event(MOUSEEVENTF_LEFTUP,q.x,q.y,0,0);

//		933 420
//943 465
//939 515
//939 552
//936 599
	}

}
