#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#include<fstream>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e4+5;
const int INF = 0x3f3f3f3f;
int Trees[20*MAX][26], tot = 1;//trees[i][j],����iΪ�ڵ��ţ�jΪ��֧��Ϣ��a-z)
int p;						//trees[i]j]��¼�ڵ�i��j��ָ֧��Ľڵ�ı��
char Str[MAX][21];  			   //tot��¼�ڵ���
int n;//�ַ�������
int sum[MAX] ;//��¼��
fstream In("data.in",ios::in);//��ȡ
fstream Out("my_data.out",ios::out);//д�� 
void init()
{
	memset(sum, 0, sizeof(sum));
}
void get_tree() {
	for(int i = 0; i < n; i++) {
		int len = strlen(Str[i]);
		int p = 1;
//		Out << "ok " << len << endl;
		for(int j = 0; j < len; j++) {
			int x = Str[i][j]-'a';
			if(Trees[p][x] == 0)
				Trees[p][x] = ++tot;

			p = Trees[p][x];
			sum[p]++;//��ǽڵ����ַ�������
			//printf("sum[%d]=%d\n", p, sum[p]);
		}
	}

}
int search_pre(int n) {
	int p = 1;
	int len = strlen(Str[n]);
	for(int i = 0; i < len; i++) {
		//Out << "Tree "<<Trees[p][str[i]-'a'] << endl;
		//	Out << "ok" <<endl;
		p = Trees[p][Str[n][i]-'a'];
		Out << Str[n][i];
		if(sum[p] == 1)
			break;
	}
	Out << endl;
}
int main() {
	FAST_IO;
	init();
	int i = 0;
	while(In >> Str[i++]) {	
		n = i;
	}
	get_tree();
	for(i = 0; i < n; i++) {
		Out << Str[i] << " ";
		search_pre(i);
	}
	In.close();
	Out.close();
}
