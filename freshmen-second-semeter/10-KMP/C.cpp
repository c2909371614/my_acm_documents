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
inline int input() {
		
		scanf("%s",str);
	//	printf("str:%s\n",str);
		if(!strcmp(str,"#") )
			return 0;
		scanf("%s",sub);
		str_n = strlen(str);
		sub_n = strlen(sub);
		return 1;
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
	int i = 0;//i��0��ʼ�� 
	int j = 0;
	while(i < str_n) {
		if(j == -1 || sub[j] == str[i]) {//-1Ϊ��ʼֵ��ֹ
			i++;
			j++;
//			printf("sub[%d]=%c str[%d]=%c\n", j, sub[j], i, str[i]);
			
				
		} else {
			j = nxt[j];
		}
		if(j == sub_n){//ab ababaa
				sum++;
				j = 0;	//	 
			}
	}
	return -1;
}

int main() {

	while(input()) {
		
//		if(str == "#")
//			break;
		init();
		get_nxt();
		find_first();
		printf("%d\n",sum); 
	}
	return 0;
}
