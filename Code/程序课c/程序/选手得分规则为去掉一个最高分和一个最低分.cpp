#include<stdio.h>
int main()
{
	int mark;
	int i,max,min,n;
	double average,sum=0;
	while(scanf("%d",&n)!=EOF){
		scanf("%d",&mark);
		min=max=mark;
		sum=mark;
		for(i=1;i<=n-1;i++){
	    	scanf("%d",&mark);
	    	
	    	
	    	sum=sum+mark;
       
			if(mark>max)
			   max=mark;
			if(mark<min) 
			   min=mark;
		}
		average=(sum-min-max)/(n-2.0);
		printf("average=%.2f\n",average);
    
	}
	return 0;
}
 
