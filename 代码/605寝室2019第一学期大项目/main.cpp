#include"mainHead.h"
void BigNum::print()    //�������
{
	int i;
	cout << a[len - 1];
	for(i = len - 2 ; i >= 0 ; i--)
	{
		cout.width(DLEN);
		cout.fill('0');
		cout << a[i];
	}
	cout << endl;
}
BigNum a,b,c;
string s1;
string s2;
int main(){
    cin>>s1>>s2;

	a = s1;
	b = s2;
	c = a + b;
	cout<<a<<" + "<<b<<" = "<<c<<endl;      //������<<���ţ�ֻ����cout���

	a = s1;
	b = s2;
    c = a - b;
    cout<<a<<" - "<<b<<" = "<<c<<endl;

    a = s1;
    b = s2;
    c = a * b;
    cout<<a<<" * "<<b<<" = "<<c<<endl;

    a = s1;
    c = a / 1000;
    cout<<a<<" / 1000 = "<<c<<endl;         //ֻ�ܳ�int���ͣ��õ��Ľ��Ϊ������

    a = s1;
    b = a % 1000;                       //ֻ�ܶ�int����ȡģ���õ��Ľ��Ϊ������
    cout<<a<<" mod 1000 = "<<c<<endl;

    a = s1;
    c = a^10;
    cout<<a<<" ^ 10 = "<<c<<endl;           //������n�η���n��int��Χ��

    a = s1;
    b = s2;
    if(a>b) puts("yes");                //��������������Ժʹ������int���ͱȴ�С
    if(a>1000)  puts("yeah");           //ֻ����>��������<��<=��.>=

    return 0;
}
