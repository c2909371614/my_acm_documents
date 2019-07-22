#include<stdio.h>
#include<math.h>
int main()
{
	bool a[1005];
	int m=2,i;
	int count=0;
	for(i=0;i<1000;i++)
		a[i]=true;
	while(m<=sqrt(1000)){
		//if(!a[i*m])continue;
		for(i=2;i*m<1000;i++)
			a[i*m]=false;
		m++; 
	}
	for(i=2;i<1000;i++)
		if(a[i]){
			printf("%-4d ",i);
			count++;
			if(count%10==0)
				printf("\n");
		}
			
	return 0;
	
}
