#include"mainHead.h"
BigNum BigNum::operator+(const BigNum & T) const   //两个大数之间的相加运算
{
	BigNum t(*this);
	int i,big;      //位数
	big = T.len > len ? T.len : len;
	for(i = 0 ; i < big ; i++)
	{
		t.a[i] +=T.a[i];
		if(t.a[i] > MAXN)
		{
			t.a[i + 1]++;
			t.a[i] -=MAXN+1;
		}
	}
	if(t.a[big] != 0)
		t.len = big + 1;
	else
		t.len = big;
	return t;
}
BigNum BigNum::operator-(const BigNum & T) const   //两个大数之间的相减运算
{
	int i,j,big;
	bool flag;
	BigNum t1,t2;
	if(*this>T)
	{
		t1=*this;
		t2=T;
		flag=0;
	}
	else
	{
		t1=T;
		t2=*this;
		flag=1;
	}
	big=t1.len;
	for(i = 0 ; i < big ; i++)
	{
		if(t1.a[i] < t2.a[i])
		{
			j = i + 1;
			while(t1.a[j] == 0)
				j++;
			t1.a[j--]--;
			while(j > i)
				t1.a[j--] += MAXN;
			t1.a[i] += MAXN + 1 - t2.a[i];
		}
		else
			t1.a[i] -= t2.a[i];
	}
	t1.len = big;
	while(t1.a[len - 1] == 0 && t1.len > 1)
	{
		t1.len--;
		big--;
	}
	if(flag)
		t1.a[big-1]=0-t1.a[big-1];
	return t1;
}
