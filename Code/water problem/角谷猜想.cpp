#include<stdio.h>
int main()
{
	int n,digit,count;
	scanf("%d",&n); 
	for(int i=1;i<=n;i++){
		scanf("%d",&digit);
		count=0;
		if(digit%2==0)digit=digit/2;
		if(digit%2==1){
				printf("%d",digit);
				digit=digit*3+1;
				count++;
			}
		while(1){
			if(digit%2==0)digit=digit/2;
		    if(digit%2==1&&digit!=1){
				printf(" %d",digit);
				digit=digit*3+1;
				count++;
			}
			if(digit==1)break;
		}//printf("count=%d\n",count);
		if(count==0)printf("No number can be output !");
		printf("\n");
	}
	return 0;
}
