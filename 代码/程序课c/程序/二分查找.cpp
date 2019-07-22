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
int main()
 {
 	int a[10]={1,2,3,4,5,6,7,8,9,10};
 	int x;
 	while(scanf("%d",&x)!=EOF){
	 	if(dou_search(a,10,x)>=0) 
			printf("a[%d]=%d\n",dou_search(a,10,x),x);
	 	else printf("not found\n");
	 }
 	return 0;
 }
