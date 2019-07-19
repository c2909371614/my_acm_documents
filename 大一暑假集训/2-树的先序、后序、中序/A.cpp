#include<bits/stdc++.h>
#define ll long long
using namespace std;//数组模拟链表 

const ll MAX = 1e5 + 5;

struct Node{
	ll val;
	ll r_index,l_index;
	Node(){//指针初始化为-1 
		r_index = -1;
		l_index = -1;
	}
}node[MAX];

ll index = 0;
ll pre[MAX], mid[MAX], mid_pos[MAX];
vector<ll>  back_val;
ll build(ll prL, ll prR, ll midL, ll midR)
{
	if(prL > prR || midL > midR)	
		return -1;
	ll now = index++;
	ll l_len = mid_pos[pre[prL]] - midL;//中序的根节点的位置 - 开头 
	node[now].val = pre[prL];//cout << prL << prR << midL << midR << endl;
	node[now].l_index = build(prL+1, prL + l_len, midL, mid_pos[pre[prL]] - 1);
	node[now].r_index = build(prL + l_len + 1, prR, mid_pos[pre[prL]] + 1, midR);
	return now;//返回模拟数组的下标 
}
void back_pass(ll n)
{
	if(n == -1)return;
	
	back_pass(node[n].l_index);
	back_pass(node[n].r_index);
	back_val.push_back(node[n].val); 
}
ll main()
{
	ll n;
	while(cin >> n)
	{
		index = 0;
		back_val.clear();
		for(ll i = 0; i < n; i++)
			cin >> pre[i];
		for(ll i = 0; i < n; i++){
			cin >> mid[i];
			mid_pos[mid[i]] = i;
		}
		back_pass(build(0, n-1, 0, n-1));
		for(ll i = 0; i < n; i++){
			cout << back_val[i];
			if(i != n-1)cout << " ";
		}
			
		cout << endl;	
	}
}
