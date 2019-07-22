#include"mainHead.h"
bool BigNum::operator>(const BigNum & T) const   //大数和另一个大数的大小比较
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
bool BigNum::operator >(const int & t) const    //大数和一个int类型的变量的大小比较
{
	BigNum b(t);
	return *this>b;
}
