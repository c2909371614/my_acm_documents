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
		//i��jƥ��֤������subǰj+1���ַ��ͺ�j+1���ַ����
		if(j == -1 || sub[j] == sub[i]) { //ƥ��Ļ�������ܻ��и����ƥ����
			j++;
			i++;
			nxt[i] = j;//ǰi���ַ���ǰ��׺���ƥ����Ϊj
		} else { //��ƥ��˵������Ķ���ƥ�䲻��Ҫ����������ǰj�����ƥ��ĵ���
			j = nxt[j];
		}
	}
}
inline int find_first() {
	int i = 0;
	int j = 0;
	while(i < str_n) {
		if(j == -1 || sub[j] == str[i]) {//-1Ϊ��ʼֵ��ֹ
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

