#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std; 
bool cl[222][222]; // �ڽӾ���
int match[222], n, m;
bool vis[222], succ[222];
int hide[222]; // ����㼯��

bool dfs(int x) {
    for (int i = 1; i <= n; i++)
        if (cl[x][i] && !vis[i]) {
            vis[i] = true;
            if (!match[i] || dfs(match[i])) {
                match[i] = x;
                return true;
            }
        }
    return false;
}

int main() {
    // ����
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y;
        scanf("%d%d", &x, &y);
        cl[x][y] = 1;
    }
    // Floyd ���ݱհ�
    for (int i = 1; i <= n; i++) cl[i][i] = 1;
    for (int k = 1; k <= n; k++) 
        for (int i = 1; i <= n; i++) 
            for (int j = 1; j <= n; j++) 
                cl[i][j] |= cl[i][k] && cl[k][j];
    for (int i = 1; i <= n; i++) cl[i][i] = 0;
    // �ڲ�����ͼ�������ƥ��
    int ans = n;
    for (int i = 1; i <= n; i++) {
        memset(vis, 0, sizeof(vis));
        ans -= dfs(i);
    }
    cout << ans <<endl;
    // ���췽�����Ȱ�����·���յ㣨�󲿷�ƥ��㣩��Ϊ�����
    for (int i = 1; i <= n; i++) succ[match[i]] = true;
    for (int i = 1, k = 0; i <= n; i++)
        if (!succ[i]) hide[++k] = i;
    memset(vis, 0, sizeof(vis));
    bool modify = true;
    while (modify) {
        modify = false;
        // ��� next(hide)
        for (int i = 1; i <= ans; i++) 
            for (int j = 1; j <= n; j++)
                if (cl[hide[i]][j]) vis[j] = true;
        for (int i = 1; i <= ans; i++)
            if (vis[hide[i]]) {
                modify = true;
                // ���������ƶ�
                while (vis[hide[i]]) hide[i] = match[hide[i]];
            }
    }
    for (int i = 1; i <= ans; i++) printf("%d ", hide[i]);
    cout << endl;
}