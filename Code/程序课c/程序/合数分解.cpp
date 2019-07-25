#include<stdio.h>
#include<math.h>
int main()
{
	int n,i=0,j,a[12]={2,3,5,7,11,13,17,19,23,29,31,37};
	int m;
	int b[105];
	for(int k=0;k<105;k++)
		b[k]=0;
	scanf("%d",&n);
	m=n;
	for(j=1;i<=10;j++){
		if(n%a[i]==0){
			b[j]=a[i];
			n=n/a[i];
		}
		else i++;
	}
	for(int k=1;k<105;k++)
		if(b[k])printf("%d ",b[k]);
	return 0;
}
