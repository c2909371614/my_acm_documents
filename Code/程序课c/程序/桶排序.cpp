#include<stdio.h>

int main(){
	int a[1000];
	int n,i,temp;
	scanf("%d",&n);
	for(i=0;i<1000;i++)
		a[i]=0;
	for (i=0;i<n;i++){
		scanf("%d",&temp);
		a[temp]++;//a[temp]!=����   temp�����������ͬ 
	}
	for(i=0;i<1000;i++){
		while(a[i]>0){
			printf("%d ",i);
			a[i]--;//��ͬ���������� 
		}
	}
	return 0; 
} 
