#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxM= 1e2+5;
int main(){
	int T;
	cin>>T;
	while(T--){
		int n,a[maxM][maxM],dp[maxM][maxM];
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<=i;j++)
				cin>>a[i][j]; 
		for(int i=0;i<n;i++)		
			dp[n-1][i]=a[n-1][i];//dp初始化从下往上 
		for(int i=n-2;i>=0;i--){
			for(int j=0;j<=i;j++){
				dp[i][j]=a[i][j]+max(dp[i+1][j],dp[i+1][j+1]);
			}
		}	
		cout<<dp[0][0]<<endl;
	} 
	} 
