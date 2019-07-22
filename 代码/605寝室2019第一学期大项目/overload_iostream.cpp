#include"mainHead.h"
istream& operator>>(istream & in,  BigNum & b)   //重载输入运算符
{
	char ch[MAXSIZE*4];
	int i = -1;
	in>>ch;
	int l=strlen(ch);
	int count=0,sum=0;
	for(i=l-1;i>=0;)
	{
		sum = 0;
		int t=1;
		for(int j=0;j<4&&i>=0;j++,i--,t*=10)
		{
			sum+=(ch[i]-'0')*t;
		}
		b.a[count]=sum;
		count++;
	}
	b.len =count++;
	return in;

}
ostream& operator<<(ostream& out,  BigNum& b)   //重载输出运算符
{
	int i;
	cout << b.a[b.len - 1];
	for(i = b.len - 2 ; i >= 0 ; i--)
	{
		cout.width(DLEN);
		cout.fill('0');
		cout << b.a[i];
	}
	return out;
}

