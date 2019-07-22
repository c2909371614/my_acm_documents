#include"mainHead.h"
BigNum BigNum::operator/(const int & b) const   //������һ�����������������
{
	BigNum ret;
	int i,down = 0;
	for(i = len - 1 ; i >= 0 ; i--)
	{
		ret.a[i] = (a[i] + down * (MAXN + 1)) / b;
		down = a[i] + down * (MAXN + 1) - ret.a[i] * b;
	}
	ret.len = len;
	while(ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}
int BigNum::operator %(const int & b) const    //������һ��int���͵ı�������ȡģ����
{
	int i,d=0;
	for (i = len-1; i>=0; i--)
	{
		d = ((d * (MAXN+1))% b + a[i])% b;
	}
	return d;
}
