#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<conio.h>
#include<time.h> 
#include<math.h>
#define X 50
#define Y 30
#define DELAY1 100
#define DELAY2 200
void Hide(){
	HANDLE Handle=GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO CursoleInfo;
	GetConsoleCursorInfo(Handle,&CursoleInfo);
	CursoleInfo.bVisible =false;
	SetConsoleCursorInfo(Handle,&CursoleInfo);
 
}
void position(int x,int y){
	COORD pos={x,y};
	HANDLE hOut=GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut,pos);
	srand(time(0));
    static int i=1;i++;
    int j=rand()%7;
	SetConsoleTextAttribute(hOut,j|i%7);
}
void clean(int x){
	position(x,pow((x-X),2)/20+5);
			printf(" ");
			position(x,pow((x-X),2)/30+5);
			printf(" ");
			position(2*X-x,pow((x-X),2)/20+5);
			printf(" ");
			position(2*X-x,pow((x-X)/2,2)/30+5);
			printf(" ");
}
int main()
{
	int x,y;
	while(true){
		x=X,y=Y;
		Hide();
		for(;y>10;y-=0.1){
			position(x,y);
			printf("**");
			Sleep(DELAY1);
			position(x,y);
			printf("  ");
		}
		for(;x>0;x--){
			position(x,pow((x-X),2)/20+5);
			printf("%");
			position(x,pow((x-X),2)/30+5);
			printf("&");
			position(2*X-x,pow((x-X),2)/20+5);
			printf("&");
			position(2*X-x,pow((x-X)/2,2)/30+5);
			printf("%");
			Sleep(DELAY2);
			clean(x);
		}
		system("cls");
		Sleep(1000);
	} 
}
