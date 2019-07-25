//¾ØÕóÏà³Ëm*p  p*n==>m*n
//c=AB{1 2 3}{1 4}	{1*1+2*2+3*3    1*4+2*5+3*6} 	{14		32} 
//	  {		}{2 5}=	{						   }= 	{		  }
//	  {4 5 6}{3 6}	{4*1+5*2+6*3	4*4+5*5+6*6} 	{32		77}
//
#include<stdio.h>
int main()
{
	int C[10][10],B[10][10],A[10][10];
	int i,j,k;
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			scanf("%d",&A[i][j]);
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++)
			scanf("%d",&B[i][j]);
	
	for(i=1;i<=3;i++)
		for(j=1;j<=3;j++){
			C[i][j]=0; 
			for(k=1;k<=3;k++)
				//for(t=1;t<=3;t++)
				C[i][j]+=A[i][k]*B[k][j];
		}
	for(i=1;i<=3;i++){ 
		for(j=1;j<=3;j++)
			printf("%-6d ",C[i][j]);		
		printf("\n");
	} 
	return 0;		
}			 
