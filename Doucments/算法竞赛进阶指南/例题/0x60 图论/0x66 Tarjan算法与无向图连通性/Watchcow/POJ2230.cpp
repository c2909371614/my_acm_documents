#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int head[10010], ver[100010], Next[100010], tot; // �ڽӱ�
int stack[100010], ans[100010]; // ģ��ϵͳջ����ջ
bool vis[100010];
int n, m, top, t;

void add(int x, int y) {
	ver[++tot] = y, Next[tot] = head[x], head[x] = tot;
}

void euler() {
	stack[++top] = 1;
	while (top > 0) {
		int x = stack[top], i = head[x];
		// �ҵ�һ����δ���ʵı�
		while (i && vis[i]) i = Next[i];
		// ����������ģ��ݹ���̣���Ǹñߣ������±�ͷ
		if (i) {
			stack[++top] = ver[i];
			head[x] = Next[i];
			// vis[i] = vis[i ^ 1] = true;
		}		
		// ��x���������б߾��ѷ��ʣ�ģ����ݹ��̣�����¼
		else {
			top--;
			ans[++t] = x;
		}
	}
}

int main() {
	cin >> n >> m;
	tot = 1;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y), add(y, x);
	}
	euler();
	for (int i = t; i; i--) printf("%d\n", ans[i]);
}