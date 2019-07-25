#include<bits/stdc++.h>
#define ll long long
#define FAST_IO  std::ios::sync_with_stdio(false)

using namespace std;

const int MAX = 2e5 + 5;

vector<int> nxt[MAX];
int color[MAX];//染色
int write_num, black_num;
int n, m;//num of vertices and edges
void dfs(int f)
{
	int s_color = 0; 
	for(int i = 0; i < nxt[f].size(); i++) {
		if(color[nxt[f][i]] == 0) {//没有被涂色 
			s_color = 3 - color[f];//与父节点颜色不同
			if(s_color == 1)
				write_num++;//记录黑白节点的个数
			else
				black_num++;
			color[nxt[f][i]] = s_color;
			dfs(nxt[f][i]);//搜索子节点
		}

	}
}
void init()
{
	for(int i = 0; i <= n; i++)
	{
		color[i] = 0;
		nxt[i].clear();
	}
	write_num = 0;
	black_num = 0;
}
int main() {
	FAST_IO;
	int T;
	cin >> T;
	int x, y;

	while(T--) {
		init();
		cin >> n >> m;
		for(int i = 0; i < m; i++) {
			cin >> x >> y;
			nxt[x].push_back(y);
			nxt[y].push_back(x);
		}
		color[1] = 1;
		write_num++;//根节点也要算 
		dfs(1);
		if(write_num <= n/2)
		{
			cout << write_num << endl;
			for(int i = 1; i <= n; i++)
			{
				if(color[i] == 1)cout << i << " ";
			}
			cout << endl;
		 } 
		else {
			cout << black_num << endl;
			for(int i = 1; i <= n; i++)
			{
				if(color[i] == 2)cout << i << " ";
			}
			cout << endl;
		}
		//cout << "sum:" << write_num + black_num << endl; 
	}
	
}
