#include<stdio.h>
int get_int(int *a)
{
	int product;
	product=*a%10;
	return product;
 } 
 int main()
 {
 	int digit,i=1,limit,a[105];
 	int j;
 	scanf("%d",&digit);
 	while(1){
 		a[i]=get_int(&digit);
 		digit/=10;
 		if(!digit)break;
 		i++;
	 }
	limit=i;
	//printf("%d\n",i);
	for(j=1;j<=limit/2;j++){//printf("a=%d a=%d",a[j],a[i]);
		if(a[j]!=a[i]){
			printf("no");
			break;
		}
		i--;
	}
	if(j>limit/2)printf("yes");
	return 0;
 }
