#include<bits/stdc++.h>
#define ll long long
//#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e4 + 5;
const ll INF = 0x3f3f3f3f;
const int N = 1e6 + 5;

int str[N];
int sub[MAX];
int str_n, sub_n;
int nxt[MAX];

inline void init()
{
	for(int i = 0; i <= sub_n; i++)
		nxt[i] = -1;
//	memset(nxt, -1, sizeof(nxt));
}
inline void input() {
	scanf("%d%d",&str_n,&sub_n); 
	for(int i = 0; i < str_n; i++) {
		scanf("%d",&str[i]);
	}
	for(int i = 0; i < sub_n; i++) {
		scanf("%d",&sub[i]);
	}
}
inline void get_nxt() {
	nxt[0] = -1;
	int i = 0, j = -1;
	while(i < sub_n) {
		//i和j匹配证明对于sub前j+1个字符和后j+1个字符相等
		if(j == -1 || sub[j] == sub[i]) { //匹配的话后面可能还有更大的匹配数
			j++;
			i++;
			nxt[i] = j;//前i个字符的前后缀最大匹配数为j
		} else { //不匹配说明后面的都不匹配不需要再找了跳到前j个最大匹配的点上
			j = nxt[j];
		}
	}
}
inline int find_first() {
	int i = 0;
	int j = 0;
	while(i < str_n) {
		if(j == -1 || sub[j] == str[i]) {//-1为初始值防止
			i++;
			j++;
			if(j == sub_n)return i - j + 1;
		} else {
			j = nxt[j];
		}
	}
	return -1;
}

int main() {
	int T;
	//cin >> T;
	scanf("%d",&T);
	while(T--) {
		input();
		init();
		get_nxt();
		printf("%d\n",find_first());
	}
	return 0;
}

