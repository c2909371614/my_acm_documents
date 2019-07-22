#include<stdio.h>
int main()
{
	int sm,cpx;//int integer整形，浮点型（实数）
			//float (6位）double (15位） 
	for(sm=1;sm<=9;sm++){
		for(cpx=1;cpx<=sm;cpx++)//j=j+1;
			printf("%d*%d=%-2d ",cpx,sm,cpx*sm);
		printf("\n");
	}
 } 
