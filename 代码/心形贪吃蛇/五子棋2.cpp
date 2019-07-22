/*����ʵ�����������Ӻ��ж�ʤ����Դ���룬����������
�����˹������㷨��ĿǰAI�������ǵ�������ӣ���ʱû
��ʵ�֡������ص㽲һ��ʤ���жϹ��ܵ�ʵ�֣����Ƕ�֪
���������л�ʤ���������������ӣ��������ӵķ�������
�֣�ˮƽ����ֱ�������Խ��߷���ɨ���˼������ÿ��
���ӵ�λ���жϸ���������ɨ��Ĵ��������Ϊ5������ˮ
ƽ����Ϊ���������±�Ϊ��5����5���Ĵӡ�5����0����ʼ
�ж������ҵ�������꣨������Ԫ�أ���ֵ�Ƿ���ȣ�������������ʤ��*/
#include <stdio.h>
#include <stdlib.h>
#define NO_CHESS    "ʮ"
#define RED_CHESS   "??"
#define BLACK_CHESS "??"
#define BOARD_SIZE  15 //�������̵Ĵ�С
typedef int DataType;
struct Stack
{
    DataType arr[BOARD_SIZE][BOARD_SIZE];

    int top;

};





//����һ����ά�������䵱����

const char *Chesses[BOARD_SIZE][BOARD_SIZE];



//----����������-----



//��ʼ������

void initChess(void);
//�������

void prChess(void);

//�ж���Ӯ

void winJudge(char* corlor,int x,int y);

//��ʾ���ʤ��

void printWin(char* color);

//����ɨ�躯��

void horizonScan(char* color,int x,int y);

//����ɨ�躯��

void verticalScan(char* color,int x,int y);

//���Խ���ɨ�躯��

void diagonalScan(char* color,int x,int y);

//���Խ���ɨ�躯��

void opposeDiagonalScan(char* color,int x,int y);

//���庯��

void retract();





//-----������ʵ��-----

//��ʼ������

void initChess(void)

{

    //��ÿһ��Ԫ�ظ�ֵΪ "ʮ" ���ڿ���̨��������

    for (int i =0; i<BOARD_SIZE; i++)

    {

        for (int k =0; k<BOARD_SIZE; k++)

        {

            Chesses[i][k] = NO_CHESS;

        }

    }



}



//�������
void prChess(void)
{



    printf("  00 01 02 03 04 05 06 07 08 09 10 11 12 13 14\n");

    //��ӡÿ������Ԫ�ص�ֵ

    for (int i =0; i<BOARD_SIZE; i++)//��

    {

        printf("%02d ",i);

        for (int k =0; k<BOARD_SIZE; k++)//��

        {

            printf("%s ",Chesses[i][k]);

        }

        

        //����

        printf("\n");

    }

}
//�ж���Ӯ
void winJudge(char* color,int x,int y)
{

    //����ɨ��

    horizonScan(color, x, y);

    //����ɨ��

    verticalScan(color, x, y);

    //�Խ��߷���ɨ��

    diagonalScan(color, x, y);

    //���Խ��߷���ɨ��

    opposeDiagonalScan(color, x, y);

}
//����ɨ�躯��
void horizonScan(char* color,int x,int y)
{

    //count�洢ɨ��Ĵ���

    int count;

    //�洢����

    int sign;

    if((8-abs(y-7))>4)

    {

        count=4;

    }else{

        count=7-abs(y-7);

    }

    //4-10��ɨ����Σ�0��14��ɨ��һ�Σ�����0�дӵ�ǰλ�ÿ�ʼɨ�裬��14�д�10��ɨ�裻����������

    for (int i=count; i>=0; i--)

    {

        //ǰ4��ֻ��ɨ�赽��0�У�����Խ��

        if (y>7)

        {

            sign=i-4;

        }else

        {

            sign=0-i;

        }

        //ɨ���Ƿ�������

        if ((*Chesses[x][y+sign]==*color)&&(*Chesses[x][y+sign+1]==*color)&&(*Chesses[x][y+sign+2]==*color)&&(*Chesses[x][y+sign+3]==*color)&&(*Chesses[x][y+sign+4]==*color))

            

                printWin(color);

        

    }

    

}
//����ɨ�躯��
void verticalScan(char* color,int x,int y)
{

    //count�洢ɨ��Ĵ���

    int count;

    //�洢����

    int sign;

    if((8-abs(x-7))>4)

    {

        count=4;

    }else

    {

        count=7-abs(x-7);

    }

    //4-10��ɨ����Σ�0��14��ɨ��һ�Σ�����0�дӵ�ǰλ�ÿ�ʼɨ�裬��14���д�10��ɨ�裻����������

    for (int i=count; i>=0; i--)

    {

        //ǰ4��ֻ��ɨ�赽��0�У�����Խ��

        if (x>7)

        {

            sign=i-4;

        }else

        {

            sign=0-i;

        }

        //ɨ���Ƿ�������

        if ((*Chesses[x+sign][y]==*color)&&(*Chesses[x+sign+1][y]==*color)&&(*Chesses[x+sign+2][y]==*color)&&(*Chesses[x+sign+3][y]==*color)&&(*Chesses[x+sign+4][y]==*color))

            

            printWin(color);

        

    }

    



}
//�Խ���ɨ�躯��/Users/tarena0036/Desktop/��Ļ���� 2016-05-04����2.16.17.png
void diagonalScan(char* color,int x,int y)
{

    //count���ڴ洢ɨ��Ĵ���

    int count;

    //�洢����

    int sign;

    //���ڴ洢��ʱ����

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

        //�����������ɨ��

        count=-1;

    }

    //(4-10)*(4-10)����ɨ����Σ�0��14��/��ɨ��һ�Σ�����0��/�дӵ�ǰλ�ÿ�ʼɨ�裬��14��/�д�10��/��ɨ�裻����������

    for (int i=count; i>=0; i--)

    {

        //ǰ4��ֻ��ɨ�赽��0�У�����Խ��

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

        //ɨ���Ƿ�������

        if ((*Chesses[x+sign][y+sign]==*color)&&(*Chesses[x+sign+1][y+sign+1]==*color)&&(*Chesses[x+sign+2][y+sign+2]==*color)&&(*Chesses[x+sign+3][y+sign+3]==*color)&&(*Chesses[x+sign+4][y+sign+4]==*color))

            

            printWin(color);

        

    }



    

}
//���Խ���ɨ��
void opposeDiagonalScan(char* color,int x,int y)
{
    //count���ڴ洢ɨ��Ĵ���

    int count;

    //�洢����

    int sign;

    //���ڴ洢��ʱ����

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

        //�����������ɨ��

        count=-1;

    }

    //(4-10)*(4-10)����ɨ����Σ�0��14��/��ɨ��һ�Σ�����0��/�дӵ�ǰλ�ÿ�ʼɨ�裬��14��/�д�10��/��ɨ�裻����������

    for (int i=count; i>=0; i--)

    {

        //ǰ4��ֻ��ɨ�赽��0�У�����Խ��

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

        //ɨ���Ƿ�������

        if ((*Chesses[x+sign][y-sign]==*color)&&(*Chesses[x+sign-1][y-sign+1]==*color)&&(*Chesses[x+sign-2][y-sign+2]==*color)&&(*Chesses[x+sign-3][y-sign+3]==*color)&&(*Chesses[x+sign-4][y-sign+4]==*color))

            

            printWin(color);

        

    }

}
//���幦��
void retract()
{
   

}
//�����ʤ��Ϣ
void printWin(char* color)
{

    printf("%s Win!\n",color);

    //��������

    exit(1);

}
//������
int main(int argc,const char * argv[])
{

    //��ʼ����ά���飬�洢�����������Ƿ��Ѿ���������Ϣ

    int info1[BOARD_SIZE][BOARD_SIZE]={0};

    //����ջ�����ڴ洢���꣬����ʱȡ��ջ��Ԫ�ؽ���Ӧλ�õĵ㸴λ

    

    

    //���ú���

    initChess();

    prChess();

    

    //��ʼѭ������

    while (1)

    {

 

        int xPos;

        int yPos;

    menu:

        printf("�����������������,��x y������15 15Ϊ���壩 \n");

        scanf("%d %d",&xPos,&yPos);

        if (xPos>BOARD_SIZE||yPos>BOARD_SIZE)

        {

            printf("���ڱ߽���������Ч����!\n");

            goto menu;

        }

        else if(xPos==BOARD_SIZE&&yPos==BOARD_SIZE)

        {

            retract();

        }

        if (1==info1[xPos][yPos])

        {

            printf("�������λ���Ѿ������ӣ����������룺\n");

            goto menu;

        }

        //���Ѿ����ӵĵ���Ϊ1

        info1[xPos][yPos]=1;

        //�Ѷ�Ӧ������Ԫ�ظ�ֵ�ɺ���

        Chesses[xPos][yPos] = RED_CHESS;

        //ˢ������

        prChess();

        //�ж��Ƿ��ʤ

        winJudge(Chesses[xPos][yPos],xPos,yPos);

        

        int macXPos,macYPos;

    macPosition:

        //�������2�� 0~15֮�������Ϊ�������������

        macXPos = arc4random()%BOARD_SIZE;

        macYPos = arc4random()%BOARD_SIZE;

        //�ж����ɵ�����Ķ�Ӧ�ĵ��Ƿ��Ѿ���������

        if (1==info1[macXPos][macYPos])

        {

            goto macPosition;

        }

        //��������������긳ֵ Ϊ ����

        Chesses[macXPos][macYPos] = BLACK_CHESS;

        //���Ѿ����ӵĵ���Ϊ1

        info1[macXPos][macYPos]=1;

        //ˢ������

        prChess();

        //�жϺ����Ƿ��ʤ

        winJudge(Chesses[macXPos][macYPos],macXPos,macYPos);

        

        

        

    }

    

    /*

     ����Ĵ��뻹�漰��������Ҫ�Ľ��ĵط�

     1���û������������Ч�ԣ�ֻ�������֣����ܳ������̵ķ�Χ(��ʱû�ж����������Ƿ������ӽ����ж�)

     2��������Ѿ�����ĵ㣬�����ظ�����(ʵ��)

     3��ÿ���������Ҫɨ��˭Ӯ��

     

     4�����幦��

     */

    return 0;

}


