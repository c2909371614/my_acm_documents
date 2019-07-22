#include<stdio.h>
int main()
{
	double rate[10]={0,0.03,0.1,0.2,0.25,0.3,0.35,0.45};
	double money[10]={0,0,1500,4500,9000,35000,55000,80000};
	double tax[10]={0,45,300,900,6500,6000,8750,1000000000000000000000000000000000};
	double m;
	scanf("%lf",&m);
	for(int i=1;i<=7;i++)
		tax[i]+=tax[i-1];
	for(int i=1;i<=7;i++){
		if(m<tax[i]){
			printf("%d",(int)((m-tax[i-1])/rate[i]+money[i])+3500);
			break;
		}
	}
    return 0;
}
