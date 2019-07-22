//1海里=1.852公里(千米) 1英尺 = 12英寸 = 0.3048米 1公斤(kg)=2.2046226磅(lb)
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
using namespace std;
void print_title()
{
	printf("enter choice :1 is sea_m to km -1 is opposite\n");
	printf("	     2 is feet to m -2 is opposite\n");
	printf("	     3 is kg to lb -3 is opposite\n");
}
void sea_m_f()
{
	double sea_m;
	scanf("%lf",&sea_m);
	printf("%3.fsea mile=%.3fkm",sea_m,sea_m*1.852);
 }
void km_f()
{	
	double km;
	scanf("%lf",&km);
	printf("%3.fkm=%.3fsea mile",km,km/1.852);
 } 
void feet_f()
{
	double feet;
	scanf("%lf",&feet);
	printf("%3.ffeet=%.3fm",feet,feet*0.3);
 }
void m_f()
{	
	double m;
	scanf("%lf",&m);
	printf("%3.fm=%.3ffeet",m,m/0.3);
 }
void kg_f()
{
	double kg;
	scanf("%lf",&kg);
	printf("%3.fkg=%.3flb",kg,kg*2.2);
 }
void lb_f()
{
	double lb;
	cin>>lb;
	printf("%.3flb=%.3fkg",lb,lb/2.2);
}
int main()
{
	print_title();
	int choice;
	while (cin>>choice){
		switch(choice){
			case 1: sea_m_f();break;case -1: km_f();break;
			case 2: feet_f();break;case -2: m_f();break;
			case 3: kg_f();break;case -3: lb_f();break;
			default:printf("enter invalid");
		} 
		printf("\n");
	}
	//cout<<choice;
 } 
