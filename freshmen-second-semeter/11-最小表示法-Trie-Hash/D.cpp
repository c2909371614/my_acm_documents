#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e4+5;
const int INF = 0x3f3f3f3f;
int Trees[20*MAX][26], tot = 1;//trees[i][j],其中i为节点编号，j为分支信息（a-z)
int p;						//trees[i]j]记录节点i的j分支指向的节点的编号
char Str[MAX][30];  			   //tot记录节点编号
int n;//字符串数量
int sum[MAX] ;//记录答案
void init()
{
	memset(sum, 0, sizeof(sum));
}
void get_tree() {
	for(int i = 0; i < n; i++) {
		int len = strlen(Str[i]);
		int p = 1;
//		cout << "ok " << len << endl;
		for(int j = 0; j < len; j++) {
			int x = Str[i][j]-'a';
			if(Trees[p][x] == 0)
				Trees[p][x] = ++tot;

			p = Trees[p][x];
			sum[p]++;//标记节点下字符串个数
			//printf("sum[%d]=%d\n", p, sum[p]);
		}
	}

}
int search_pre(int n) {
	int p = 1;
	int len = strlen(Str[n]);
	for(int i = 0; i < len; i++) {
		//cout << "Tree "<<Trees[p][str[i]-'a'] << endl;
		//	cout << "ok" <<endl;
		p = Trees[p][Str[n][i]-'a'];
		cout << Str[n][i];
		if(sum[p] == 1)
			break;
	}
	cout << endl;
}
int main() {
	FAST_IO;
	init();
	int i = 0;
	while(cin >> Str[i++]) {	
		n = i;
	}
	get_tree();
	for(i = 0; i < n; i++) {
		cout << Str[i] << " ";
		search_pre(i);
	}

}
