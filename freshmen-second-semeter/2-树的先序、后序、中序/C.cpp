#include<bits/stdc++.h>
using namespace std;

int const MAX = 1e5 + 5;
int const NUM = 1e5+5;
vector<int> nxt[MAX];//后节点

#define FAST_IO ios::sync_with_stdio(false)

int color[NUM];
int n, m, N = 0;//节点数，边数 
bool flag = true;
void __init()
{
	for(int i = 0; i < NUM; i++)
		nxt[i].clear();
	
	for(int i = 0; i < NUM; i++)
		color[i] = -1;
	flag = true;
}
void dfs(int s)
{
	//cout << N++ << endl;
	for(int i = 0; i < nxt[s].size(); i++)
	{
		if(color[s] == color[nxt[s][i]])
			flag = false;
		else if(color[nxt[s][i]] == -1){
			color[nxt[s][i]] = 3- color[s];
			dfs(nxt[s][i]);
		}
	}
}
int main()
{
	FAST_IO;
	int T;
	cin >> T;
	int temp = T;
	while(temp--)
	{
		__init();
		int s;
		cin >> n >> m >> s; 
		
		for(int i = 0; i < m; i++)
		{
			int x, y;
			cin >> x >> y;
			nxt[x].push_back(y);
			nxt[y].push_back(x); 
		}
		color[s] = 1;
		dfs(s);
		cout << "Case " << T - temp << ": ";
		if(!flag)
			cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	return 0;
}
