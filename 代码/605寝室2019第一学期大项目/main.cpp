#include"mainHead.h"
void BigNum::print()    //输出大数
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
	cout<<a<<" + "<<b<<" = "<<c<<endl;      //重载了<<符号，只能用cout输出

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
    cout<<a<<" / 1000 = "<<c<<endl;         //只能除int类型，得到的结果为大数类

    a = s1;
    b = a % 1000;                       //只能对int类型取模，得到的结果为大数类
    cout<<a<<" mod 1000 = "<<c<<endl;

    a = s1;
    c = a^10;
    cout<<a<<" ^ 10 = "<<c<<endl;           //大数的n次方，n在int范围内

    a = s1;
    b = s2;
    if(a>b) puts("yes");                //重载运算符，可以和大数类或int类型比大小
    if(a>1000)  puts("yeah");           //只能用>，不能用<、<=、.>=

    return 0;
}
