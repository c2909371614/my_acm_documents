#include<stdio.h>

int main(){
	int a[1000];
	int n,i,temp;
	scanf("%d",&n);
	for(i=0;i<1000;i++)
		a[i]=0;
	for (i=0;i<n;i++){
		scanf("%d",&temp);
		a[temp]++;//a[temp]!=个数   temp与输入的数相同 
	}
	for(i=0;i<1000;i++){
		while(a[i]>0){
			printf("%d ",i);
			a[i]--;//相同的数的排序 
		}
	}
	return 0; 
} 
