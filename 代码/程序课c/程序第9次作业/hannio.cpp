#include<stdio.h>
int num=1;
int hanio(int n,char a,char b,char c) 
{
	if(n==1)
		printf("%c-->%c\n",a,b);
	if(n>1) {
		hanio(n-1,a,c,b);num++;
		printf("%c-->%c\n",a,b);
		hanio(n-1,c,b,a);num++;
	}		
}
//int total(int n){
//	if(n==1)return n;
//	else return total(n-1)+1+total(n-1);
//}
int main(){
	int n;
	char a='A',b='B',c='C';
	scanf("%d",&n); 
	hanio(n,a, b,c);
	printf("%d %d\n",num,total(n));
}
