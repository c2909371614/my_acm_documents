#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "interface.h"
#include "snake.h"

char interf[M][N];

void newinterface(struct snake *snake,  int fx, int fy,int s)
{
    int x, y;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (i == 0 || i == M - 1)
                interf[i][j] = '-';
                //printf("-");
            else if (j == 0)
                interf[i][j] = '|';
                //printf("|");
            else if (j == N - 1)
                interf[i][j] = '|';
                //printf("|\n");
            else if (i == fy && j == fx)
                interf[i][j] = '$';
                //printf("$");
            else  
                interf[i][j] = ' ';
                //printf(" ");
        }
    }
    for (; s >= 0; s--)
    {
            x = (snake + s)->snake_x;
            y = (snake + s)->snake_y;
            interf[y][x] = '@';
    }   
}

void food(int *x, int *y,int *fx,int *fy,int *s, struct snake *snake)
{
    int ffx, ffy;//��һ��ʳ���XY����
    ffx = *fx;
    ffy = *fy;

    if (*x == *fx && *y == *fy)//����Ե���ʳ�������һ��ʳ��
    { 
        do {
            *fx = 1 + rand() % (N - 3);
            *fy = 1 + rand() % (M - 3);
        } while (ffx == *fx && ffy == *fy);//��֤���ϴ�ʳ��λ�ò�ͬ

        for (int i= (*s); i >= 0; i--)
        {
            if ((snake + *s)->snake_x == *fx && (snake + *s)->snake_y == *fy) {
                *fx = 1 + rand() % (N - 3);
                *fy = 1 + rand() % (M - 3);
            }
        }//����ʱ�֤ʳ���������ӵ�λ�ò�ͬ��������ȫ��֤��
        (*s)++ ;                          //������һ!!!!!!!
    }
}


void control(int *x,int *y,int *X,int *Y)//xy����ͷ�����꣬XY�ǿ����˶��������
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'w' :
        case 'W' :
            if(interf[*y - 1][*x]!='@'){   //if��䱣֤�߲��ܵ�����
                *X = 0; *Y = -1;
            }
            break;
        case 'd':
        case 'D':
            if(interf[*y][*x + 1] != '@'){
                *X = 1; *Y = 0;
            }
                break;
        case 's':
        case 'S':
            if (interf[*y + 1][*x] != '@') {
                *X = 0; *Y = 1;
            }
                break;
        case 'a':
        case 'A':
            if (interf[*y][*x - 1] != '@') {
                *X = -1; *Y = 0;
            }
                break;
        default:
            break;
        } 
    }
    *x = *x + *X;//�ı�һ��λ��
    *y = *y + *Y;
}


void draw(void)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c", interf[i][j]);
        }
        printf("\n");
    }
}


void death(int x,int y,int s)
{
    if (x == 0 || x == N-1 || y  == 0 || y == M-1 || interf[y][x] == '@') {
        for (;;)
        {
            system("cls");
            printf("\n              ��Ϸ������\n");
            printf("              ���յ÷֣�%d \n", s);
            Sleep(140);
        //system("pause");
        }

    }
}

