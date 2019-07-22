#include<stdio.h>
#include<string.h>
#include<ctype.h>
bool num(char *p)
{
	for(int i=0;i<17;i++)
		if(!isdigit(p[i]))return false;
	if(isdigit(p[17])||p[17]=='x');
	else return false;
	return true;
}
void turn(char *p)
{
	for(int i=0;i<=16;i++)
		p[i]-='0';
}
void date(char *p)
{
	printf("%d%d%d%d.%d%d.%d%d",p[6],p[7],p[8],p[9],p[10],p[11],p[12],p[13]);
	printf("\n");
}
void sex(char *p){
	if(p[16]%2)printf("you are a boy\n");
	else printf("you are a girl\n");
}
int main()
{
	
	
		int m[20]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		char a[100];
		gets(a);
		int flag=0;
		if(strlen(a)!=18)flag++;
		else if(!num(a))flag++;
		turn (a);//string turn to digit.
		int year=a[6]*1000+a[7]*100+a[8]*10+a[9];
		int month=a[10]*10+a[11],day=a[12]*10+a[13];
		if(year%4==0&&year%100!=0||year%400)m[2]++;
		if(day>m[month]||month>12)flag++;
		if(flag){
			printf("the IDcard is illegal.\n");
		}
		else {
			printf("your Idcard is legal and your birthday:");
			date(a);sex(a);
			printf("\n");
		}
		//printf("%d %d %d %d",flag,year,month,day);	
	
	return 0;
 } 
