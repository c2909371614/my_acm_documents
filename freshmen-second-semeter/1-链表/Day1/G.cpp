#include <bits/stdc++.h>
using namespace std;
const int N = 105;

/*
There are many solutions for this problem,
here is the cycle linkedlist way.Every node 
have two dirctions, just build them with
prev and next, prev for clockwise, and next
for counterclockwise, travel the linked
list, you'll get the answer.
============================================
Sorry for that my editer doesn't fit utf-8
*/

int n, u, v, w;
int pre[N], nxt[N];
int dis[N][N];

int main() {
    cin >> n;
    memset(pre, -1, sizeof pre);
    memset(nxt, -1, sizeof nxt);
    
    for (int i = 1; i <= n; i++) {
        cin >> u >> v >> w;
        dis[u][v] = w;
        if (pre[u] == -1) pre[u] = v;
        else nxt[u] = v;
        if (pre[v] == -1) pre[v] = u;
        else nxt[v] = u;
    }

    int now = 1;
    do {
        if (pre[nxt[now]] != now)
            swap(pre[nxt[now]], nxt[nxt[now]]);
        now = nxt[now];
    } while (now != 1);
    
    int ans1 = 0, ans2 = 0;
    
    now = 1;
    do {
        ans1 += dis[nxt[now]][now];
        now = nxt[now];
    } while (now != 1);
    
    now = 1;
    do {
        ans2 += dis[pre[now]][now];
        now = pre[now];
    } while (now != 1);
    
    cout << min(ans1, ans2) << endl;
    return 0;
}