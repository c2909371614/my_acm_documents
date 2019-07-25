#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int head[10010], ver[100010], edge[100010], Next[100010], tot; // �ڽӱ�
int stack[100010], ans[100010]; // ģ��ϵͳջ����ջ
bool vis[100010];
int deg[100010]; // �ڵ���� 
int n, m, top, t;

void add(int x, int y, int z) {
	ver[++tot] = y, edge[tot] = z, Next[tot] = head[x], head[x] = tot;
}

void euler() {
	stack[++top] = 2; vis[2] = vis[3] = true;
	while (top > 0) {
		int e = stack[top], x = ver[e], i = head[x];
		// �ҵ�һ����δ���ʵı�
		while (i && vis[i]) i = Next[i];
		// ����������ģ��ݹ���̣���Ǹñߣ������±�ͷ
		if (i) {
			stack[++top] = i;
			head[x] = Next[i];
			vis[i] = vis[i ^ 1] = true;
		}		
		// ��x���������б߾��ѷ��ʣ�ģ����ݹ��̣�����¼
		else {
			ans[++t] = edge[stack[top]];
			top--;
		}
	}
}

int main() {
	int x, y, z;
	while (~scanf("%d%d", &x, &y) && x) {
		tot = 1, t = 0, top = 0;
		memset(deg, 0, sizeof(deg));
		memset(head, 0, sizeof(head));
		memset(vis, 0, sizeof(vis));
		do {
			scanf("%d", &z);
			add(x, y, z), add(y, x, z);
			deg[x]++, deg[y]++;
		} while (~scanf("%d%d", &x, &y) && x);
		// �ж�ŷ����·�Ƿ���� 
		bool flag = false;
		for (int i = 1; i <= 50; i++)
			if (deg[i] & 1) flag = true;
		if (flag) {
			puts("Round trip does not exist.");
			continue;
		}
		euler();
		for (int i = t; i > 1; i--) printf("%d ", ans[i]);
		printf("%d\n", ans[1]);
	}
}
