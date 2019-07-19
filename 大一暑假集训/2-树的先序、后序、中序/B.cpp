#include<bits/stdc++.h>
#define ll long long
using namespace std;//数组模拟链表 

const ll MAX = 1e5 + 5;
ll tm1 = 0,tm2 = 0;
ll N=0;
ll vis[MAX];
vector<ll> node[MAX];//储存node[n]能够到达点的节点 
void dfs(ll n, ll depth)
{
	vis[n] = 1;
	if(depth % 2) tm1++; 
	else tm2++;
	for(ll i = 0; i < node[n].size(); i++){
		if(!vis[node[n][i]])
			dfs(node[n][i], depth + 1);
		//cout<<" "<<N++<<endl; 
	}
}
int main()
{
	ll n;
	cin >> n;
	ll x, y;
	for(ll i = 0; i < n - 1; i++){
		cin >> x >> y;
		node[x].push_back(y);
		node[y].push_back(x);
	} 
	dfs(1, 1);
//	cout << tm1 + tm2 <<endl;
	cout << tm1*tm2 - (n - 1) << endl;
}
