#include<stdio.h>
#include<stdlib.h>
#include<time.h> 
int main()
{

	int mynumber,yournumber,i;
	srand(time(0));
	mynumber=rand()%100+1;
	for(i=1;i<=7;i++){
	    printf("enter yournumber:");
	    scanf("%d",&yournumber);	
	    if(mynumber==yournumber){ 
	        printf("lucky you");break;
		}
	    else if(yournumber>mynumber)
	        printf("too big\n");
	    else if(yournumber<mynumber)
	  	    printf("too small\n");   
	}
	printf("the answer is %d",mynumber);
    return 0;
} 
