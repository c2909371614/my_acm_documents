#include<bits/stdc++.h>
#define ll long long
const int MAX=1005;
using namespace std;
int ans[MAX][MAX][2],p[MAX];//p为位置 
int main()
{
	ll T;
	cin>>T;
	ll n,w;//w为初始位置 
	while(T--)
	{
		cin>>n>>w;
		int index; 
		for(int i=0;i<n;i++){
			cin>>p[i]; 
		}
		p[n]=w;
		sort(p,p+n+1);
		for(int i=0;i<=n;i++)
			if(p[i]==w)index=w-1,ans[i][i][0]=ans[i][i][1]=0;
			else ans[i][i][0]=ans[i][i][1]=0x3fffffff;
		
		for(int i=index;i>=0;i--){ 
			for(int j=i+1;j<=n;j++){//ans[i][j][0] 在i 
				ans[i][j][0]=min(ans[i+1][j][0]+(p[i+1]-p[i])*(n-(j-(i+1))),ans[i+1][j][1]+(p[j]-p[i])*(n-(j-(i+1))));
				ans[i][j][1]=min(ans[i][j-1][1]+(p[j]-p[j-1])*(n-((j-1)-i)),ans[i][j-1][0]+(p[j]-p[i])*(n-((j-1)-i)));
				//cout<<min(ans[i][j][0],ans[i][j][1])<<" ";
			}
			//cout<<endl;
		}
		cout<<min(ans[0][n][0],ans[0][n][1])<<endl;
	}
	
}
