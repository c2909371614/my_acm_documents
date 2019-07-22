#include"mainHead.h"
BigNum::BigNum(const int b)     //��һ��int���͵ı���ת��Ϊ����
{
	int c,d = b;
	len = 0;
	memset(a,0,sizeof(a));
	while(d > MAXN)
	{
		c = d - (d / (MAXN + 1)) * (MAXN + 1);
		d = d / (MAXN + 1);
		a[len++] = c;
	}
	a[len++] = d;
}
BigNum::BigNum(const string&s)     //��һ���ַ������͵ı���ת��Ϊ����
{
	int t,k,index,l,i;
	memset(a,0,sizeof(a));
	l=s.size();
	len=l/DLEN;
	if(l%DLEN)
		len++;
	index=0;
	for(i=l-1;i>=0;i-=DLEN)
	{
		t=0;
		k=i-DLEN+1;
		if(k<0)
			k=0;
		for(int j=k;j<=i;j++)
			t=t*10+s[j]-'0';
		a[index++]=t;
	}
}
BigNum::BigNum(const BigNum & T) : len(T.len)  //�������캯��
{
	int i;
	memset(a,0,sizeof(a));
	for(i = 0 ; i < len ; i++)
		a[i] = T.a[i];
}
BigNum & BigNum::operator=(const BigNum & n)   //���ظ�ֵ�����������֮����и�ֵ����
{
	int i;
	len = n.len;
	memset(a,0,sizeof(a));
	for(i = 0 ; i < len ; i++)
		a[i] = n.a[i];
	return *this;
}
