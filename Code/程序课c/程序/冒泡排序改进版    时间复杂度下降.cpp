#include<stdio.h>
int main()
{
	int a[1005];
	int max,temp,n;
	while(~scanf("%d",&n)){
		
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		for(int i=1;i<n;i++){
			int flag=0;
			for(int j=1;j<=n-i;j++)
				if(a[j]>a[j+1]){
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
					flag++;
				}	
			if(!flag)break;	
		}
		for(int i=1;i<=n;i++)
			printf("%d ",a[i]);
		printf("\n");
	}
 }
