#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
long long f[21][4];
int t, n, m;

void prework() {
	f[0][0] = 1;
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 3; j++) {
			f[i + 1][j + 1] += f[i][j];
			f[i + 1][0] += f[i][j] * 9;
		}
		f[i + 1][3] += f[i][3] * 10;
	}
}

int main() {
	prework();
	cin >> t; // ��������
	while (t--) {
		scanf("%d", &n); // ��Ŀ�е�X
		// ��n��ħ������mλ
		for (m = 3; f[m][3] < n; m++);
		// �����iλ��ĩβ����k��6��k=3Ҳ��ʾ�Ѿ���ħ������
		for (int i = m, k = 0; i; i--) {
			// ��С����ö�ٵ�iλ�������j
			for (int j = 0; j <= 9; j++) {
				// �����ߵ�i-1λ�ж������������������ħ����
				long long cnt = f[i - 1][3];
				if (j == 6 || k == 3)
					for (int l = max(3 - k - (j == 6), 0); l<3; l++)
						cnt += f[i - 1][l];
				// ���cnt��nС��˵����n��ħ�����ĵ�iλӦ�ñ�j����
				if (cnt < n) {
					n -= cnt;
				}
				// ���򣬵�iλ��Ӧ����j
				else {
					if (k < 3) {
						if (j == 6) k++; else k = 0;
					}
					printf("%d", j);
					break;
				}
			}
		}
		cout << endl;
	}
}
