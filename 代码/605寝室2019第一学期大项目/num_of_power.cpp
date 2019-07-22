#include"mainHead.h"
BigNum BigNum::operator^(const int & n) const    //大数的n次方运算
{
	BigNum t,ret(1);
	int i;
	if(n<0)
		exit(-1);
	if(n==0)
		return 1;
	if(n==1)
		return *this;
	int m=n;
	while(m>1)
	{
		t=*this;
		for( i=1;i<<1<=m;i<<=1)
		{
			t=t*t;
		}
		m-=i;
		ret=ret*t;
		if(m==1)
			ret=ret*(*this);
	}
	return ret;
}
