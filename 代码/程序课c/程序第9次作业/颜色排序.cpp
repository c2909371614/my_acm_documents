#include<stdio.h>
#include<string.h>
void fsort (char *color[],int n)
{
	int i,j;
	char *temp;
	bool flag;
	for(i=1;i<n;i++){ 
		flag=true;
		for(j=0;j<n-i;j++){
			if(strcmp(color[j],color[j+1])>0){
				temp=color[j];
				color[j]=color[j+1];
				color[j+1]=temp;
				flag=false;
			}
		}
		if(flag)break;
	} 
 }
 int main()
 {
 	char *color[5]={"red","blue","yellow","green","black"};
 	fsort(color,5);
 	for(int i=0;i<5;i++)
 		puts(color[i]);
 	return 0;
  } 
