#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE* sq;
	int i=0; 
	while(true){
		if((sq=(fopen("E:\\sq\\open.txt","a")))!=NULL)
			printf("success");
		
		i%=100000000;
		fprintf(sq,"%d\n",i++);
		
	} 
	fclose(sq);
 } 
