#include<bits/stdc++.h>
#define ll long long
//#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e4 + 5;
const ll INF = 0x3f3f3f3f;
const int N = 1e6 + 5;

char str[N];
char sub[MAX];
int str_n, sub_n;
int nxt[MAX];
int sum = 0;
inline void init()
{
	for(int i = 0; i <= sub_n; i++)
		nxt[i] = -1;
//	memset(nxt, -1, sizeof(nxt));
	sum = 0;
}
inline void input() {
		scanf("%s",sub);
		scanf("%s",str);
		str_n = strlen(str);
		sub_n = strlen(sub);
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
	int i = 0;//i从0开始搜 
	int j = 0;
	while(i < str_n) {
		if(j == -1 || sub[j] == str[i]) {//-1为初始值防止
			i++;
			j++;
//			printf("sub[%d]=%c str[%d]=%c\n", j, sub[j], i, str[i]);
			
				
		} else {
			j = nxt[j];
		}
		if(j == sub_n){//ab ababaa
				sum++;
				j = nxt[j];	//	 
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
		find_first();
		printf("%d\n",sum); 
	}
	return 0;
}

