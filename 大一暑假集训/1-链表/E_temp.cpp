#include<bits/stdc++.h>
#define ll long long
#define FAST_IO ios::sync_with_stdio(false)
using namespace std;
const int MAX=2e5+5;
int pos;
int num[MAX];
int head[MAX];//访问信息1 -7 数值 
int index[MAX];
int Prev[MAX],Next[MAX];
int find_max() { //最后即最大
	while(head[pos])
		pos--;
	return pos;//到零停止
}
void del(int now) {
	Next[Prev[now]] = Next[now];
	Prev[Next[now]] = Prev[now];
}
int main() {
	ll n, k;
	cin >> n >> k;
	int x;
	memset(head, 0, sizeof(head));
	for(int i = 1; i <= n; i++) {
		cin >> x;
		num[i] = x;
		index[x] = i;
		Prev[i] = i - 1;
		Next[i] = i + 1;
	}
//	for(int i = 1; i <= n; i++)
//		cout << i << " " << Prev[index[i]] << " " << Next[index[i]] <<endl; 
	int ans[MAX];//答案
	int sum=0;
	int flag=0;
	pos = n;//从最大的开始 
	while(find_max()) {
		int now = pos;
		int pre = Prev[index[pos]], nxt = Next[index[pos]];//前后指针
		//cout << " " << pre << nxt << now << index[pos] << endl;
		int temp_k = k;//替换 
		while(temp_k-- && pre > 0) {
			ans[pre] = flag % 2 + 1;
			del(pre);
			head[num[pre]] = 1; //标记数值 
			pre = Prev[pre];
			
		}
		temp_k = k;
		while(temp_k-- && nxt <= n)
		{
			ans[nxt] = flag % 2 + 1;
			del(nxt);
			head[num[nxt]] = 1; //标记 
			nxt = Next[nxt];
		 } 
		ans[index[now]] = flag % 2 + 1;
		del(index[now]);
		head[now] = 1;//标记 
		flag++;
//		for(int i = 1; i <= n; i++)
//			cout << head[i] <<" ";
//		cout << endl;
	}
	
	for(int i = 1; i <= n; i++)
		cout << ans[i];
}
