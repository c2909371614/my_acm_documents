#include<bits/stdc++.h>
#define ll long long
#define FAST_IO  std::ios::sync_with_stdio(false);
using namespace std;
const int MAX = 1e6 + 5;

ll dp[MAX], sum[MAX];
stack<int> a,b;
string type;
int in_num;
int cur = 0;//指针 
int main()
{
	FAST_IO;
	int n;
	while(cin >> n)
	{
		memset(dp, 0, sizeof(dp));
		memset(sum, 0,sizeof(sum));//初始化 
		while(!a.empty())a.pop();
		while(!b.empty())b.pop();
		cur = 0;
		dp[0] = -MAX;
		while(n--)
		{
			cin >> type;
			if(type == "I"){
				cin >> in_num;
				a.push(in_num);
				sum[++cur] = sum[cur-1] + in_num;
				dp[cur] = max(dp[cur-1], sum[cur]);//前缀和最大
//				cout << "sum[" << cur << "]:" << sum[cur] << endl;
//				cout << "dp[" << cur << "]:" << dp[cur] << endl; 
			} 
			else if(type == "D"){
//				b.push(a.top());
				a.pop();
				cur--;
//				cout << "sum[" << cur << "]:" << sum[cur] << endl;
//				cout << "dp[" << cur << "]:" << dp[cur] << endl;
			} 
			else if(type == "L" && !a.empty())
			{
				b.push(a.top());
				a.pop();
				cur--;
			 } 
//				cout << "dp[" << cur << "]:" << dp[cur] << endl;
//				cout << "sum[" << cur << "]:" << sum[cur] << endl;
			 else if(type == "R" && !b.empty())
			 {
				in_num = b.top();
			 	a.push(in_num);
			 	sum[++cur] = sum[cur-1] + in_num;
				dp[cur] = max(dp[cur-1], sum[cur]);//前缀和最大
			 	b.pop();
//			 	cout << "sum[" << cur << "]:" << sum[cur] << endl;
//				cout << "dp[" << cur << "]:" << dp[cur] << endl;
			 }
			 else if(type == "Q")
			 {
			 	cin >> in_num;
			 	cout << dp[in_num] << endl;
			 }
		}
	}
	return 0;
}

