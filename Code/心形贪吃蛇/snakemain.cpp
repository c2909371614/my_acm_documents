#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "interface.h"
#include "snake.h"
#define SPEED 100//speed 
void Hide() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  
	CONSOLE_CURSOR_INFO CursorInfo;  
	GetConsoleCursorInfo(handle, &CursorInfo);//��ȡ����̨�����Ϣ  
	CursorInfo.bVisible = false; //���ؿ���̨���  
	SetConsoleCursorInfo(handle, &CursorInfo);//���ÿ���̨���״̬   
}
int main(void)
{
    struct snake a[(M - 2)*(N - 2)];
    int snake_x =4;
    int snake_y =4;
    int X = 1;
    int Y = 0;
    int food_x , food_y ;
    int score = 0;

    do {
        food_x = 1 + rand() % (N - 3);
        food_y = 1 + rand() % (M - 3);
    } while (food_x == 4 && food_y == 4);

    for (;;)
    {
    	Hide();
        //system("cls");
        COORD pos={0,0};
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),pos);
        printf("\n                       ̰����С��Ϸ\n");
//        printf("\n���ߣ�xhyang ���͵�ַ��http://blog.csdn.net/weixin_39449570\n");
        printf("��W���������˶�����D���������˶�����S���������˶�����A���������˶���\n");
        printf("�÷֣�%d",score);
        printf("\n");

        control(&snake_x, &snake_y,&X,&Y);
        build_snake(a, score, &snake_x, &snake_y);
        death(snake_x, snake_y,score);
        newinterface(a, food_x, food_y, score);
        food(&snake_x, &snake_y, &food_x, &food_y,&score,a);
        draw();
        Sleep(SPEED);
    }
    system("pause");
    return 0;
}
