#ifndef MAIN
#define MAIN 
#include<iostream>
#include<cstring>
#include<cstdio>
//#include<iomanip>
#include<algorithm>
using namespace std;

#define MAXN 9999
#define MAXSIZE 10
#define DLEN 4

class BigNum
{
private:
	int a[1500];    //���Կ��ƴ�����λ��
	int len;       //��������
public:
	BigNum(){ len = 1;memset(a,0,sizeof(a)); }   //���캯��
	BigNum(const int);       //��һ��int���͵ı���ת��Ϊ����
	BigNum(const string&);     //��һ���ַ������͵ı���ת��Ϊ����
	BigNum(const BigNum &);  //�������캯��
	BigNum &operator=(const BigNum &);   //���ظ�ֵ�����������֮����и�ֵ����

	friend istream& operator>>(istream&,  BigNum&);   //�������������
	friend ostream& operator<<(ostream&,  BigNum&);   //������������

	BigNum operator+(const BigNum &) const;   //���ؼӷ����������������֮����������
	BigNum operator-(const BigNum &) const;   //���ؼ������������������֮����������
	BigNum operator*(const BigNum &) const;   //���س˷����������������֮����������
	BigNum operator/(const int   &) const;    //���س����������������һ�����������������

	BigNum operator^(const int  &) const;    //������n�η�����
	int    operator%(const int  &) const;    //������һ��int���͵ı�������ȡģ����
	bool   operator>(const BigNum & T)const;   //��������һ�������Ĵ�С�Ƚ�
	bool   operator>(const int & t)const;      //������һ��int���͵ı����Ĵ�С�Ƚ�

	void print();       //�������
}; 
#endif
