#include<iostream>

#include<windows.h>

#include<winuser.h>

using namespace std;

int main()

{



// return 0;

	while(true)

	{
		POINT P;

		GetCursorPos(&P);

		int x1=P.x;

		int y1=P.y;
		cout<<x1<<" "<<y1<<endl;

		Sleep(4000);

		mouse_event(MOUSEEVENTF_LEFTDOWN,x1,y1,0,0);

		mouse_event(MOUSEEVENTF_LEFTUP,x1,y1,0,0);

	}

}
