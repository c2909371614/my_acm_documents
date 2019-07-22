#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "interface.h"
#include "snake.h"
#define SPEED 100//speed 
void Hide() {
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);  
	CONSOLE_CURSOR_INFO CursorInfo;  
	GetConsoleCursorInfo(handle, &CursorInfo);//获取控制台光标信息  
	CursorInfo.bVisible = false; //隐藏控制台光标  
	SetConsoleCursorInfo(handle, &CursorInfo);//设置控制台光标状态   
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
        printf("\n                       贪吃蛇小游戏\n");
//        printf("\n作者：xhyang 博客地址：http://blog.csdn.net/weixin_39449570\n");
        printf("按W控制向上运动，按D控制向右运动，按S控制向下运动，按A控制向左运动。\n");
        printf("得分：%d",score);
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
