#include"mainHead.h"
BigNum BigNum::operator*(const BigNum & T) const   //两个大数之间的相乘运算
{
	BigNum ret;
	int i,j,up;
	int temp,temp1;
	for(i = 0 ; i < len ; i++)
	{
		up = 0;
		for(j = 0 ; j < T.len ; j++)
		{
			temp = a[i] * T.a[j] + ret.a[i + j] + up;
			if(temp > MAXN)
			{
				temp1 = temp - temp / (MAXN + 1) * (MAXN + 1);
				up = temp / (MAXN + 1);
				ret.a[i + j] = temp1;
			}
			else
			{
				up = 0;
				ret.a[i + j] = temp;
			}
		}
		if(up != 0)
			ret.a[i + j] = up;
	}
	ret.len = i + j;
	while(ret.a[ret.len - 1] == 0 && ret.len > 1)
		ret.len--;
	return ret;
}
