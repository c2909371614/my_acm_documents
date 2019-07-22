#include<stdio.h>
#include<math.h>
int main()
{
	double a;
	int integer;
	while(scanf("%lf",&a)!=EOF){
		integer=(int)a;
		a-=integer;
		puts("a binary system is:");
		while(integer!=0){
			printf("%d",integer%2);
			integer/=2;
		}
		printf(".");
		while(a!=0){
			printf("%d",(int)(a*2));
			a=a*2-(int)(a*2);
		}
		puts("");
	}
}
