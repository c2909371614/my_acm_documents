#include<bits/stdc++.h>
using namespace std;
const int maxM=1e2+5;
#define ll long long
int dp(int weight[],int value[],int n,int all_weight) { //n为物体个数
	int dp[maxM][maxM];
	for(int i=0; i<maxM; i++)
		memset(dp[i],0,sizeof(dp[1]));
	for(int i=1; i<=n; i++) {
		for(int j=1; j<=all_weight; j++) { //j为子背包大小
			if(i==1)
				dp[i][j]=(j>=weight[i]?value[i]:0);
			else
				dp[i][j]=max(dp[i-1][j],(j-weight[i]>=0)?(dp[i-1][j-weight[i]]+value[i]):0);//dp[i][j-weight[i]]为放入物体i后剩余空间的最大价值
		}
	}
//	for(int i=1; i<=n; i++) {
//		for(int j=1; j<=all_weight; j++) {
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}

	return dp[n][all_weight];
}
int main() {
	int weight[maxM],value[maxM];
	int n,all_weight;
	int T;
	cin>>T;
	while() {
		cin>>n>>all_weight;
		for(int i=1; i<=n; i++) {
			cin>>value[i];
		}
		for(int i=1; i<=n; i++)
			cin>>weight[i];
		cout<<dp(weight,value,n,all_weight)<<endl;
	}
}
