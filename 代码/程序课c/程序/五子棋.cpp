#include <iostream>
#include <conio.h>
#include<cstring> 
#define Chesssize 14
using namespace std;


/*������*/
class Chess;


class Player
{
public:
Player(char *p,char q)
{
strcpy(name, p);
symbol = q;
}
~Player()
{}
bool playchess(int a, int b, Chess& obj);
char* getname();
bool winner(Chess& odj)const;
bool nowinner(Chess& obj)const;
private:
char name[10];
char symbol;
};


char* Player::getname()
{
return name;
}


class Chess
{
public:
Chess()
{}
~Chess()
{}
void showchess()const;
void initchess();
friend class Player;
private:
char chess[Chesssize][Chesssize];
};


bool Player::nowinner(Chess& obj)const
{
Chess temp;
for (int i = 0; i < Chesssize; i++)
{
for (int j = 0; j < Chesssize; j++)
{
temp.chess[i][j] = obj.chess[i][j];
}
}
for (int i = 0; i < Chesssize; i++)
{
for (int j = 0; j < Chesssize; j++)
{
if (temp.chess[i][j] == '.')
{
temp.chess[i][j] = this->symbol;
}
}
}
if (!winner(temp))
{
return true;
}
else
{
return false;
}
}


bool Player::winner(Chess& obj)const
{
//����5��
int i, j, k;
for ( i = 0; i < Chesssize ; i++)
{
for ( j = 0; j < Chesssize - 4; j++)
{
for ( k = 0; k < 5; k++)
{
if (obj.chess[i][j + k] != this->symbol)
{
break;
}
}
if (k == 5)
{
return true;
}
}
}
//����5��
for (i = 0; i < Chesssize - 4 ; i++)
{
for (j = 0; j < Chesssize ; j++)
{
for (k = 0; k < 5; k++)
{
if (obj.chess[i + k][j ] != this->symbol)
{
break;
}
}
if (k == 5)
{
return true;
}
}
}
//����б5��
for (i = 0; i < Chesssize - 4 ; i++)
{
for (j = 4; j < Chesssize; j++)
{
for (k = 0; k < 5; k++)
{
if (obj.chess[i + k][j - k] != this->symbol)
{
break;
}
}
if (k == 5)
{
return true;
}
}
}
//����б5��
for (i = 0; i < Chesssize - 4; i++)
{
for (j = 0; j < Chesssize - 4; j++)
{
for (k = 0; k < 5; k++)
{
if (obj.chess[i + k][j + k] != this->symbol)
{
break;
}
}
if (k == 5)
{
return true;
}
}
}
return false;
}


void Chess::initchess()
{
memset(chess, '.', sizeof(chess));
}


void Chess::showchess()const
{
for (int i = -1; i < Chesssize;i++)
cout << i << "\t";
cout << endl;
for (int i = 0; i < Chesssize; i++)
{
cout << i<<"\t";
for (int j = 0; j < Chesssize; j++)
{
cout << chess[i][j]<<"\t";
}
cout << endl << endl;
}
}


bool Player::playchess(int a, int b, Chess& obj)
{
if (obj.chess[a][b] == '.')
{
obj.chess[a][b] = symbol;
return true;
}
else
{
cout << "����������ˣ�������������Ŷ��" << endl << endl;
return false;
}
}
/*������*/


int main()
{
Chess ce;
Player x("����", 'o');
Player y("����", 'x');
ce.initchess();
cout << "******************************************************************************************************************" << endl;
cout << "******************************************************************************************************************" << endl;
cout << "*****************************************************�������ս***************************************************" << endl;
cout << "***************************************************�����ߣ�������һ����*******************************************" << endl;
cout << "****************************************************������������������********************************************" << endl;
cout << "******************************************************2017.8.4****************************************************" << endl;
cout << "******************************************************************************************************************" << endl;
cout << endl << endl;
cout << "���������ַ�����enter��ʼ!" << endl;
_getch();
system("cls");
cout << x.getname() << ":�Ͻ�����֮�գ���ʿ����֮ʱ��" << endl;
cout << y.getname() << ":������磬��������" << endl;
ce.showchess();
while (1)
{
if (x.nowinner(ce) && y.nowinner(ce))
{
cout << "˫������!��Ϸ����!" << endl;
break;
}
int a, b;
while (1)
{
cout << "��" << x.getname() << "����:" << endl;
cin >> a >> b;
if (a >= Chesssize || b >= Chesssize || a < 0 || b <0 )
{
cout << "���Ӳ���ȷ�����������ӣ�" << endl;
continue;
}
int ret = x.playchess(a, b, ce);
if (ret)
{
break;
}
}
system("cls");
cout << x.getname() << ":�Ͻ�����֮�գ���ʿ����֮ʱ��" << endl;
cout << y.getname() << ":������磬��������" << endl;
ce.showchess();
if (x.winner(ce))
{
cout << "��ϲ��"<<x.getname() << "Ӯ��" << endl;
break;
}
while (1)
{
cout << "��" << y.getname() << "����:" << endl;
cin >> a >> b;
if (a >= Chesssize || b >= Chesssize || a < 0 || b <0)
{
cout << "���Ӳ���ȷ�����������ӣ�" << endl;
continue;
}
int ret = y.playchess(a, b, ce);
if (ret)
{
break;
}
}
system("cls");
cout << x.getname() << ":�Ͻ�����֮�գ���ʿ����֮ʱ��" << endl;
cout << y.getname() << ":������磬��������" << endl;
ce.showchess();
}
return 0;

}

