#include<stdio.h>
int main() 
{
	int n,i,num1,num2,num3,num4,num5;
	char pi;
	scanf("%d",&n);
	getchar();
	for(i=1;i<=n;i++){
		num1=num2=num3=num4=num5=0;
		while(scanf("%c",&pi)!=EOF){
			switch(pi){
				case 'a':num1++;break;
				case 'e':num2++;break;
				case 'i':num3++;break;
				case 'o':num4++;break;
				case 'u':num5++;break;
				default:break;
			}
			if(pi=='\n')break;
		}
		printf("a:%d\ne:%d\ni:%d\no:%d\nu:%d\n",num1,num2,num3,num4,num5);
		if(i!=n)printf("\n");
	}
	return 0;
 } 
