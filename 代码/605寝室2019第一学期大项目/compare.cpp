#include"mainHead.h"
bool BigNum::operator>(const BigNum & T) const   //��������һ�������Ĵ�С�Ƚ�
{
	int ln;
	if(len > T.len)
		return true;
	else if(len == T.len)
	{
		ln = len - 1;
		while(a[ln] == T.a[ln] && ln >= 0)
			ln--;
		if(ln >= 0 && a[ln] > T.a[ln])
			return true;
		else
			return false;
	}
	else
		return false;
}
bool BigNum::operator >(const int & t) const    //������һ��int���͵ı����Ĵ�С�Ƚ�
{
	BigNum b(t);
	return *this>b;
}
