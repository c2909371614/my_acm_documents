#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char filename[100];
	puts("enter filename");  
	//gets(filename);
	if(remove("11.txt")==0){
		printf("remove successfully\n");
	}
	else exit(0); 
 } 
