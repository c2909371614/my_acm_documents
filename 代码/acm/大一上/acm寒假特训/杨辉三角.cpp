#include<stdio.h>//printf(),scanf(),puts,gets,putchar,getchar
#include<string.h>//strcat,strlen,strcpy,memset()
int main(){
	int i,j;//int a[100](0-99);a[i]=10;a[1]=100;
	int a[100][100];
	for(i=0;i<100;i++)
		memset(a[i],0,sizeof(a[i]));
	a[0][1]=1;
	int n;
	puts("enter n:");
	scanf("%d",&n);
	for(i=1;i<=n;i++){
		for(j=1;j<=i;j++){
			a[i][j]=a[i-1][j-1]+a[i-1][j];
			printf("%-4d",a[i][j]);
		}
		puts("");
	}
}
