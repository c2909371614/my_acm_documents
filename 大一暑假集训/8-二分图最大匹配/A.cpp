#include<bits/stdc++.h>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false);
using namespace std;

const int MAX = 1e3 + 5;
int k, m, n;
vector<int> nxt[MAX];//女生有好感的男生
int vis[MAX], boy[MAX];//boy【i】属于哪个女生
int sum = 0;
void init() {
	//memset(girl, 0, sizeof(girl));
	for(int i = 0; i <= m; i++)
		nxt[i].clear();
	for(int i = 0; i <= n; i++)
		boy[i] = 0;
	sum = 0;
}
bool dfs_f(int x) {
	int len = nxt[x].size();
	int boy_i = -1;
	for(int i = 0; i < len; i++) {
		boy_i = nxt[x][i];
		//cout << "ok" << endl;
		if(!vis[boy_i])//如果没有考虑过该男孩
		 { 
			vis[boy_i] = 1;//访问标记
			if(boy[boy_i] == 0 || dfs_f(boy[boy_i])) { //男孩是否有归属，无归属带走，有就去访问他的女票
				//是否有备胎有的话抢走，没有就算了
				boy[boy_i] = x;//宣誓主权
				return true;
			}
		}

	}
	return false;//单身了
}
int main() {
	int x, y;
	while(cin >> k && k != 0) {
		init();//初始化
		cin >> m >> n;
		for(int i = 0; i < k; i++) {
			cin >> x >> y;
			nxt[x].push_back(y);//可以接受的
		}
		for(int i = 1; i <= m; i++) {
			memset(vis, 0, sizeof(vis));
			if(dfs_f(i))sum++;//配对成功就++
		}
		cout << sum << endl;
	}
}
