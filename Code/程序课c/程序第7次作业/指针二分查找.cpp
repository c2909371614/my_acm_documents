#include<stdio.h>
int dou_search(int *p,int n,int x)
{
	int low,mid,high;
	low=0;
	high=n-1;
	while(low<=high){
		mid=(low+high)/2;
		if(x==p[mid])break;
		else if(x>p[mid])low=mid+1;
		else high=mid-1;
	}
	if(low>high)return -1;
	else return mid;
 } 
 void pup(int b[])
 {
	int temp,n;
	for(int i=1;i<10;i++){
		for(int j=0;j<10-i;j++){
			if(b[j]>b[j+1]){
				temp=b[j];
				b[j]=b[j+1];
				b[j+1]=temp;
			}	
		}	
	}
}
int main()
 {
 	int a[10];
 	int x;
 	for(int i=0;i<10;i++)
 		scanf("%d",&a[i]);
 	pup(a);//Ã°ÅÝ 
 	for(int i=0;i<10;i++)
 		printf("%d ",a[i]);
 	printf("\n");
 	scanf("%d",&x);
	if(dou_search(a,10,x)>=0) //¶þ·Ö²éÕÒ 
		printf("a[%d]=%d\n",dou_search(a,10,x),x);
	else printf("not found\n");
	
 	return 0;
 }
