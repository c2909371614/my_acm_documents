#include<stdio.h>
void back(long long n){
	long long i; 
	for (i=1;i<=n/2;i++) 
		if(n%i==0)break;
	if(i>n/2&&n!=1)printf("YES\n");
	else printf("NO\n");
} 
int main(){
	int T,i;
	long long x,y;
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		scanf("%d%d",&x,&y);
		if(x-y==1)back(x+y);
		else printf("NO");
	}
	
}
