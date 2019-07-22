/*这是实现五子棋落子和判断胜负的源代码，电脑落子涉
及的人工智能算法（目前AI属于弱智的随机落子）暂时没
有实现。本文重点讲一下胜负判断功能的实现，我们都知
道五子棋中获胜的条件就是五联子，而五联子的方向有四
种：水平、竖直和两个对角线方向。扫描的思想是在每个
落子的位置判断各个方向能扫描的次数（最多为5）。以水
平方向为例，数组下标为【5】【5】的从【5】【0】开始
判断连往右的五个坐标（即数组元素）的值是否相等，如果是则表明获胜。*/
#include <stdio.h>
#include <stdlib.h>
#define NO_CHESS    "十"
#define RED_CHESS   "??"
#define BLACK_CHESS "??"
#define BOARD_SIZE  15 //定义棋盘的大小
typedef int DataType;
struct Stack
{
    DataType arr[BOARD_SIZE][BOARD_SIZE];

    int top;

};





//定义一个二维数组来充当棋盘

const char *Chesses[BOARD_SIZE][BOARD_SIZE];



//----函数的声明-----



//初始化棋盘

void initChess(void);
//输出棋盘

void prChess(void);

//判断输赢

void winJudge(char* corlor,int x,int y);

//提示获得胜利

void printWin(char* color);

//横向扫描函数

void horizonScan(char* color,int x,int y);

//纵向扫描函数

void verticalScan(char* color,int x,int y);

//正对角线扫描函数

void diagonalScan(char* color,int x,int y);

//反对角线扫描函数

void opposeDiagonalScan(char* color,int x,int y);

//悔棋函数

void retract();





//-----函数的实现-----

//初始化棋盘

void initChess(void)

{

    //把每一个元素赋值为 "十" 用于控制台画出棋盘

    for (int i =0; i<BOARD_SIZE; i++)

    {

        for (int k =0; k<BOARD_SIZE; k++)

        {

            Chesses[i][k] = NO_CHESS;

        }

    }



}



//输出棋盘
void prChess(void)
{



    printf("  00 01 02 03 04 05 06 07 08 09 10 11 12 13 14\n");

    //打印每个数组元素的值

    for (int i =0; i<BOARD_SIZE; i++)//行

    {

        printf("%02d ",i);

        for (int k =0; k<BOARD_SIZE; k++)//列

        {

            printf("%s ",Chesses[i][k]);

        }

        

        //换行

        printf("\n");

    }

}
//判断输赢
void winJudge(char* color,int x,int y)
{

    //横向扫描

    horizonScan(color, x, y);

    //纵向扫描

    verticalScan(color, x, y);

    //对角线方向扫描

    diagonalScan(color, x, y);

    //反对角线方向扫描

    opposeDiagonalScan(color, x, y);

}
//横向扫描函数
void horizonScan(char* color,int x,int y)
{

    //count存储扫描的次数

    int count;

    //存储变量

    int sign;

    if((8-abs(y-7))>4)

    {

        count=4;

    }else{

        count=7-abs(y-7);

    }

    //4-10列扫描五次，0和14列扫描一次；其中0列从当前位置开始扫描，而14列从10列扫描；其他列类似

    for (int i=count; i>=0; i--)

    {

        //前4列只能扫描到第0列，不能越界

        if (y>7)

        {

            sign=i-4;

        }else

        {

            sign=0-i;

        }

        //扫描是否五联子

        if ((*Chesses[x][y+sign]==*color)&&(*Chesses[x][y+sign+1]==*color)&&(*Chesses[x][y+sign+2]==*color)&&(*Chesses[x][y+sign+3]==*color)&&(*Chesses[x][y+sign+4]==*color))

            

                printWin(color);

        

    }

    

}
//纵向扫描函数
void verticalScan(char* color,int x,int y)
{

    //count存储扫描的次数

    int count;

    //存储变量

    int sign;

    if((8-abs(x-7))>4)

    {

        count=4;

    }else

    {

        count=7-abs(x-7);

    }

    //4-10行扫描五次，0和14行扫描一次；其中0行从当前位置开始扫描，而14行列从10行扫描；其他行类似

    for (int i=count; i>=0; i--)

    {

        //前4行只能扫描到第0行，不能越界

        if (x>7)

        {

            sign=i-4;

        }else

        {

            sign=0-i;

        }

        //扫描是否五联子

        if ((*Chesses[x+sign][y]==*color)&&(*Chesses[x+sign+1][y]==*color)&&(*Chesses[x+sign+2][y]==*color)&&(*Chesses[x+sign+3][y]==*color)&&(*Chesses[x+sign+4][y]==*color))

            

            printWin(color);

        

    }

    



}
//对角线扫描函数/Users/tarena0036/Desktop/屏幕快照 2016-05-04下午2.16.17.png
void diagonalScan(char* color,int x,int y)
{

    //count用于存储扫描的次数

    int count;

    //存储变量

    int sign;

    //用于存储临时数据

    int temp;

    if((8-abs(x-7))>4&&(8-abs(y-7))>4)

    {

        count=4;

    }

    else if(x<11&&y<11)

    {

        temp=x<=y?x:y;

        count=7-abs(temp-7);

    }

    else if (x>3&&y>3)

    {

        temp=x>=y?x:y;

        count=7-abs(temp-7);

        

    }

    else if (abs(x-y)==10)

    {

        count=0;

    }

    else if (abs(x-y)==9)

    {

        count=1;

    }

    else if (abs(x-y)==8)

    {

        count=2;

    }

    else

    {

        //其他情况无需扫描

        count=-1;

    }

    //(4-10)*(4-10)区域扫描五次，0和14行/列扫描一次；其中0行/列从当前位置开始扫描，而14行/列从10行/列扫描；其他行类似

    for (int i=count; i>=0; i--)

    {

        //前4行只能扫描到第0行，不能越界

        if (x+y<14)

        {

            if (x==11||y==11)

            {

                sign=-(i+1);

            }

            else

            sign=-i;

        }else

        {

            if (x==2||y==2)

            {

                sign=i-2;

            }

            else if (x==3||y==3)

            {

                sign=i-3;

            }

            else

            sign=i-4;

        }

        //扫描是否五联子

        if ((*Chesses[x+sign][y+sign]==*color)&&(*Chesses[x+sign+1][y+sign+1]==*color)&&(*Chesses[x+sign+2][y+sign+2]==*color)&&(*Chesses[x+sign+3][y+sign+3]==*color)&&(*Chesses[x+sign+4][y+sign+4]==*color))

            

            printWin(color);

        

    }



    

}
//反对角线扫描
void opposeDiagonalScan(char* color,int x,int y)
{
    //count用于存储扫描的次数

    int count;

    //存储变量

    int sign;

    //用于存储临时数据

    int temp;

    if((8-abs(x-7))>4&&(8-abs(y-7))>4)

    {

        count=4;

    }

    else if(x<11&&y>3)

    {

        temp=(abs(x-7))>=(abs(y-7))?x:y;

        count=7-abs(temp-7);

    }

    else if (x>3&&y<11)

    {

        temp=(abs(x-7))>=(abs(y-7))?x:y;

        count=7-abs(temp-7);

        

    }

    else if ((x+y)==4||(x+y)==24)

    {

        count=0;

    }

    else if ((x+y)==5||(x+y)==23)

    {

        count=1;

    }

    else if ((x+y)==6||(x+y)==22)

    {

        count=2;

    }

    else

    {

        //其他情况无需扫描

        count=-1;

    }

    //(4-10)*(4-10)区域扫描五次，0和14行/列扫描一次；其中0行/列从当前位置开始扫描，而14行/列从10行/列扫描；其他行类似

    for (int i=count; i>=0; i--)

    {

        //前4行只能扫描到第0行，不能越界

        if (x>y)

        {

            if (x==3||y==11)

            {

                sign=i+1;

            }

            else

                sign=i;

        }else

        {

            if (x==12||y==2)

            {

                sign=i+2;

            }

            else if (x==11||y==3)

            {

                sign=i+3;

            }

            else

                sign=i+4;

        }

        //扫描是否五联子

        if ((*Chesses[x+sign][y-sign]==*color)&&(*Chesses[x+sign-1][y-sign+1]==*color)&&(*Chesses[x+sign-2][y-sign+2]==*color)&&(*Chesses[x+sign-3][y-sign+3]==*color)&&(*Chesses[x+sign-4][y-sign+4]==*color))

            

            printWin(color);

        

    }

}
//悔棋功能
void retract()
{
   

}
//输出获胜信息
void printWin(char* color)
{

    printf("%s Win!\n",color);

    //结束程序

    exit(1);

}
//主函数
int main(int argc,const char * argv[])
{

    //初始化二维数组，存储棋盘坐标点的是否已经有棋子信息

    int info1[BOARD_SIZE][BOARD_SIZE]={0};

    //定义栈，用于存储坐标，悔棋时取出栈顶元素将对应位置的点复位

    

    

    //调用函数

    initChess();

    prChess();

    

    //开始循环下棋

    while (1)

    {

 

        int xPos;

        int yPos;

    menu:

        printf("请输入您下棋的坐标,如x y（输入15 15为悔棋） \n");

        scanf("%d %d",&xPos,&yPos);

        if (xPos>BOARD_SIZE||yPos>BOARD_SIZE)

        {

            printf("请在边界内输入有效数字!\n");

            goto menu;

        }

        else if(xPos==BOARD_SIZE&&yPos==BOARD_SIZE)

        {

            retract();

        }

        if (1==info1[xPos][yPos])

        {

            printf("您输入的位置已经有棋子，请重新输入：\n");

            goto menu;

        }

        //将已经落子的点标记为1

        info1[xPos][yPos]=1;

        //把对应的数组元素赋值成红棋

        Chesses[xPos][yPos] = RED_CHESS;

        //刷新棋盘

        prChess();

        //判断是否获胜

        winJudge(Chesses[xPos][yPos],xPos,yPos);

        

        int macXPos,macYPos;

    macPosition:

        //随机生成2个 0~15之间的数作为电脑下棋的坐标

        macXPos = arc4random()%BOARD_SIZE;

        macYPos = arc4random()%BOARD_SIZE;

        //判断生成的坐标的对应的点是否已经有棋子了

        if (1==info1[macXPos][macYPos])

        {

            goto macPosition;

        }

        //将电脑下棋的坐标赋值 为 黑旗

        Chesses[macXPos][macYPos] = BLACK_CHESS;

        //将已经落子的点标记为1

        info1[macXPos][macYPos]=1;

        //刷新棋盘

        prChess();

        //判断黑棋是否获胜

        winJudge(Chesses[macXPos][macYPos],macXPos,macYPos);

        

        

        

    }

    

    /*

     上面的代码还涉及到如下需要改进的地方

     1、用户输入坐标的有效性，只能是数字，不能超出棋盘的范围(暂时没有对整个棋盘是否落满子进行判断)

     2、如果是已经下棋的点，不能重复下棋(实现)

     3、每次下棋后，需要扫描谁赢了

     

     4、悔棋功能

     */

    return 0;

}


