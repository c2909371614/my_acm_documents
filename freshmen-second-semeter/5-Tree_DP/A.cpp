#include<bits/stdc++.h>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false);
using namespace std;

const int MAX = 1e4 + 5;

class Tree_DP {
	private:
		vector<int> nxt[MAX];//��¼�ӽڵ�
		int is_son[MAX];//�Ƿ�Ϊ�ӽڵ�
		int val[MAX];//��Ӧ�ڵ��ֵ
		int sum_val[2][MAX];//��������ֵ
		int num;//�ڵ����
		int root;
	public:
		void init() {
			for(int i = 0; i <= num; i++)
				nxt[i].clear(),
				is_son[i] = 0,
				val[i] = 0;
		}
		void input(int n) {
			num = n;
			init();
			for(int i = 1; i <= num; i++)
				cin >> val[i];
			int l,k;
			cin >> l >>k;
			while(l != 0 && k != 0) { //�������������
				nxt[k].push_back(l);
				is_son[l] = 1;

				cin >> l >> k;
			}
		}
		void dp(int x) {
			sum_val[0][x] = 0;
			sum_val[1][x] = val[x];
			for(int i = 0; i < nxt[x].size(); i++) {
				int y = nxt[x][i];
				dp(y);//���ӽڵ����dp
				sum_val[0][x] += max(sum_val[0][y], sum_val[1][y]);
				sum_val[1][x] += sum_val[0][y];
			}
		}
		int get_root() {
			for(int i = 1; i <= num; i++) {
				//cout << "is_son-" << i << "-" << is_son[i] << endl;
				if(!is_son[i]) {
					root = i;
					//cout << " " << i << endl;
					return i;
				}
			}
		}
		void output() {
			cout << max(sum_val[0][root], sum_val[1][root]) << endl;
		}
};

int main() {
	FAST_IO;
	Tree_DP T;
	int n;

	while(cin >> n) {
		T.input(n);
		T.dp(T.get_root());
		T.output();
	}

}
