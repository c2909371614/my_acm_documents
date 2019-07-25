#include<stdio.h>
#include<windows.h>
#include<math.h>
#include<time.h>
#include<conio.h>
void position(int x,int y){ 
	HANDLE hOut;
    COORD pos={x,y};
    hOut=GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hOut,pos);
    srand(time(0));
    static int i=1;i++;
    int j=rand()%7;
	SetConsoleTextAttribute(hOut,j|i%7);
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
	float x,y;
	Restart:
	Hide();
    while(1){
    	for(int i=0,j=6;;i++){
    		for(x=-20;x<100;x+=0.001){
    			y=10*sin(x/j);
    			position(int(x+20),(y+20));
				printf("I love you");
			//Sleep(10);
				}
			/*if(i%2==0)j=3;*/system("cls");
		}
    	if(kbhit())break;
	}
	//system("pause");
	while(1)
		if(kbhit())break;
			
		
	goto Restart;
    return 0;
}

