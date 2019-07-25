#include <iostream>
#include <conio.h>
#include<cstring> 
#define Chesssize 14
using namespace std;


/*五子棋*/
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
//横着5个
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
//竖着5个
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
//左下斜5个
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
//右下斜5个
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
cout << "这儿有棋子了，不可以落子了哦！" << endl << endl;
return false;
}
}
/*五子棋*/


int main()
{
Chess ce;
Player x("锐雯", 'o');
Player y("亚索", 'x');
ce.initchess();
cout << "******************************************************************************************************************" << endl;
cout << "******************************************************************************************************************" << endl;
cout << "*****************************************************五子棋大战***************************************************" << endl;
cout << "***************************************************制作者：国服第一锐雯*******************************************" << endl;
cout << "****************************************************请输入棋盘坐标落子********************************************" << endl;
cout << "******************************************************2017.8.4****************************************************" << endl;
cout << "******************************************************************************************************************" << endl;
cout << endl << endl;
cout << "输入任意字符按下enter开始!" << endl;
_getch();
system("cls");
cout << x.getname() << ":断剑重铸之日，骑士归来之时！" << endl;
cout << y.getname() << ":死亡如风，常伴吾身！" << endl;
ce.showchess();
while (1)
{
if (x.nowinner(ce) && y.nowinner(ce))
{
cout << "双方和棋!游戏结束!" << endl;
break;
}
int a, b;
while (1)
{
cout << "请" << x.getname() << "落子:" << endl;
cin >> a >> b;
if (a >= Chesssize || b >= Chesssize || a < 0 || b <0 )
{
cout << "落子不正确，请重新落子！" << endl;
continue;
}
int ret = x.playchess(a, b, ce);
if (ret)
{
break;
}
}
system("cls");
cout << x.getname() << ":断剑重铸之日，骑士归来之时！" << endl;
cout << y.getname() << ":死亡如风，常伴吾身！" << endl;
ce.showchess();
if (x.winner(ce))
{
cout << "恭喜："<<x.getname() << "赢了" << endl;
break;
}
while (1)
{
cout << "请" << y.getname() << "落子:" << endl;
cin >> a >> b;
if (a >= Chesssize || b >= Chesssize || a < 0 || b <0)
{
cout << "落子不正确，请重新落子！" << endl;
continue;
}
int ret = y.playchess(a, b, ce);
if (ret)
{
break;
}
}
system("cls");
cout << x.getname() << ":断剑重铸之日，骑士归来之时！" << endl;
cout << y.getname() << ":死亡如风，常伴吾身！" << endl;
ce.showchess();
}
return 0;

}

