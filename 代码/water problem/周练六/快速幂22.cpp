#include<stdio.h>
#include<math.h>
int pow4(int a,int b)
{
	int ans=1;
	while(b){
		if(b%2==1) ans=(ans*a)%10;
		a=(a*a)%10;
		b/=2;
	}
	return ans;
 } 
int main()
{
	int T;int N;
	while (~scanf("%d",&T))
		while(T--){
			scanf("%d",&N);
			printf("%d\n",pow4(N,N)); //printf("%d n=%d %d\n",(int)pow(N,N),N,(int)pow(5,5));
		}
	//return 0;
}
