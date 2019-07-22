#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
const int N = 15, M = 531441;
const int p[13] = { 1,3,9,27,81,243,729,2187,6561,19683,59049,177147,531441 }; // 3��0~12�η�
int n, m, bit[N], zero[N];
int a[N][N], f[2][M];

int main() {
	cin >> n >> m;
	memset(a, 0x3f, sizeof(a));
	for (int i = 1; i <= m; i++) {
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = a[y][x] = min(a[x][y], z);
	}
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++) f[1][p[i - 1]] = 0;
	for (int i = 1; i <= n; i++) { // ���
		for (int j = 1; j < M; j++) { // ״̬
			if (f[i & 1][j] == 0x3f3f3f3f) continue;
			int s = j; // ����Ϊ2��λ��Ϊ1�õ���״̬��Ϊs
			int last = 0; // ״̬j���λ��1
			int t = 0;
			for (int x = 1, k = j; x <= n; x++, k /= 3) { // ȡ��j��ÿһλ
				bit[x] = k % 3; // j�ĵ�x-1λ����ڵ�x
				if (bit[x] == 2) s -= p[x - 1];
				else if (bit[x] == 1) last = x;
				else zero[t++] = x;
			}

			// ��1��ת�ƣ�������չ��i�㣬��ʼ��չ��һ��
			f[i + 1 & 1][s] = min(f[i + 1 & 1][s], f[i & 1][j]);

			if (last) {
				// ��2��ת�ƣ��ڵ�i����չ״̬j���λ��1
				int x = last;
				while (t--) {
					int y = zero[t];
					if (a[x][y] == 0x3f3f3f3f) continue;
					s = j + 2 * p[y - 1]; // ��y-1λ��Ϊ2�õ�����״̬
					f[i & 1][s] = min(f[i & 1][s], f[i & 1][j] + i * a[x][y]); // ת��
				}

				// ��3��ת�ƣ��ڵ�i�㲻��չ״̬j���λ��1�������Լ�����չ����λ��1
				s = j + p[x - 1]; // ��x-1λ��1��Ϊ2
				f[i & 1][s] = min(f[i & 1][s], f[i & 1][j]); // ת��
			}
			f[i & 1][j] = 0x3f3f3f3f;
		}
	}
	int s = 0;
	for (int i = 1; i <= n; i++) s += p[i - 1];
	cout << f[n + 1 & 1][s] << endl;
}
