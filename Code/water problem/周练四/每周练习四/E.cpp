#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 52
long long dp[N];

int main(){
	dp[0]=1;
	dp[1]=1;
	for(int i=2;i<N;i++){
		dp[i]=dp[i-1]+dp[i-2];
	}
	int n;
	while(scanf("%d",&n)!=EOF){
		printf("%lld\n",dp[n]);
	}
	return 0;
}

