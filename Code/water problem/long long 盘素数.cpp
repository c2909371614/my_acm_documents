#include<stdio.h>
#include<math.h>
void back(long long n){
	int i;
	//printf("%d",n); 
	for (i=2;i<=sqrt(n);i++) 
		if(n%i==0)break;
	if(i>sqrt(n)&&n!=1)printf("yes\n");
	else printf("no\n");
} 
int main(){
	int T,i;
	long long x,y;
	scanf("%d",&T);
	for(i=1;i<=T;i++){
		scanf("%lld%lld",&x,&y);
		//printf("%lld %lld",x-y,x+y);
		if(x-y==1)back(x+y);
		else printf("no\n");
	}
	
}
