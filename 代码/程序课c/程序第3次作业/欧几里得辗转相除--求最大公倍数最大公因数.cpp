#include<stdio.h>
#include<stdlib.h>
int factor(int a,int b){
	if(b==0)return a;
	else return factor(b,a%b);
}
int main(){
	int a,b,factor1;
	scanf("%d%d",&a,&b);
	factor1=factor(a,b);
	printf("factor=%d mutiple=%d",factor1,a*b/factor1);
}
