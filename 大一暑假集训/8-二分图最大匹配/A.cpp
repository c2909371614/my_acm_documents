#include<bits/stdc++.h>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false);
using namespace std;

const int MAX = 1e3 + 5;
int k, m, n;
vector<int> nxt[MAX];//Ů���кøе�����
int vis[MAX], boy[MAX];//boy��i�������ĸ�Ů��
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
		if(!vis[boy_i])//���û�п��ǹ����к�
		 { 
			vis[boy_i] = 1;//���ʱ��
			if(boy[boy_i] == 0 || dfs_f(boy[boy_i])) { //�к��Ƿ��й������޹������ߣ��о�ȥ��������ŮƱ
				//�Ƿ��б�̥�еĻ����ߣ�û�о�����
				boy[boy_i] = x;//������Ȩ
				return true;
			}
		}

	}
	return false;//������
}
int main() {
	int x, y;
	while(cin >> k && k != 0) {
		init();//��ʼ��
		cin >> m >> n;
		for(int i = 0; i < k; i++) {
			cin >> x >> y;
			nxt[x].push_back(y);//���Խ��ܵ�
		}
		for(int i = 1; i <= m; i++) {
			memset(vis, 0, sizeof(vis));
			if(dfs_f(i))sum++;//��Գɹ���++
		}
		cout << sum << endl;
	}
}
