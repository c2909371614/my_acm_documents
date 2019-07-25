#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, k, p;
//a用于数据储存 vis用于保存数据是否被访问，
//其中下表示数据信息最后一个为最大 
int a[N], vis[N], ans[N], pos[N];//全局数组变量默认为0 
int pre[N], nxt[N];//前指针和后指针 

int nxt_max() {//访问 
    while(vis[p]) p--;
    return p;
}

void del(int x) {//数组模拟链表  
    pre[nxt[x]] = pre[x];
    nxt[pre[x]] = nxt[x];
    vis[a[x]] = 1;// 
}

int main() {
    cin >> n >> k;
    p = n;//p初始为最后 
    for (int i = 1; i <= n; i++) (cin >> a[i]), pos[a[i]] = i;//pos记录a[i]的位置 
    for (int i = 1; i <= n + 1; i++) pre[i] = i - 1;//初始化前指针 
    for (int i = 0; i <= n; i++) nxt[i] = i + 1;//初始化后指针 
    int tag = 1;// tag为答案记录1 or 2  
    while (nxt_max()) {
        int now = pos[p];//以最后一个数的位置开始 
        int tmp = pre[now];//tmp表示当前位置的前标 
        int cnt = k;//cnt临时代替k 
        while (cnt-- && tmp > 0) {//k次操作 防止溢出 
            del(tmp); //删除当前 
            ans[tmp] = tag; //导入答案 
            tmp = pre[tmp]; //向前推一个 
        }
        cnt = k;//重置cnt 
        tmp = nxt[now];//向后推 
        while(cnt-- && tmp < n + 1) {
            del(tmp);
            ans[tmp] = tag;
            tmp = nxt[tmp];
        }
        del(now);//删除当前 
        ans[now] = tag;
        tag = 3 - tag;//变换tag 
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
    cout << endl;
    return 0;
}
