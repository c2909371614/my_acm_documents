#include<stdio.h>
int main()
{
	int sm,cpx;//int integer���Σ������ͣ�ʵ����
			//float (6λ��double (15λ�� 
	for(sm=1;sm<=9;sm++){
		for(cpx=1;cpx<=sm;cpx++)//j=j+1;
			printf("%d*%d=%-2d ",cpx,sm,cpx*sm);
		printf("\n");
	}
 } 
