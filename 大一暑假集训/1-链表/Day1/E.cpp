#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, k, p;
//a�������ݴ��� vis���ڱ��������Ƿ񱻷��ʣ�
//�����±�ʾ������Ϣ���һ��Ϊ��� 
int a[N], vis[N], ans[N], pos[N];//ȫ���������Ĭ��Ϊ0 
int pre[N], nxt[N];//ǰָ��ͺ�ָ�� 

int nxt_max() {//���� 
    while(vis[p]) p--;
    return p;
}

void del(int x) {//����ģ������  
    pre[nxt[x]] = pre[x];
    nxt[pre[x]] = nxt[x];
    vis[a[x]] = 1;// 
}

int main() {
    cin >> n >> k;
    p = n;//p��ʼΪ��� 
    for (int i = 1; i <= n; i++) (cin >> a[i]), pos[a[i]] = i;//pos��¼a[i]��λ�� 
    for (int i = 1; i <= n + 1; i++) pre[i] = i - 1;//��ʼ��ǰָ�� 
    for (int i = 0; i <= n; i++) nxt[i] = i + 1;//��ʼ����ָ�� 
    int tag = 1;// tagΪ�𰸼�¼1 or 2  
    while (nxt_max()) {
        int now = pos[p];//�����һ������λ�ÿ�ʼ 
        int tmp = pre[now];//tmp��ʾ��ǰλ�õ�ǰ�� 
        int cnt = k;//cnt��ʱ����k 
        while (cnt-- && tmp > 0) {//k�β��� ��ֹ��� 
            del(tmp); //ɾ����ǰ 
            ans[tmp] = tag; //����� 
            tmp = pre[tmp]; //��ǰ��һ�� 
        }
        cnt = k;//����cnt 
        tmp = nxt[now];//����� 
        while(cnt-- && tmp < n + 1) {
            del(tmp);
            ans[tmp] = tag;
            tmp = nxt[tmp];
        }
        del(now);//ɾ����ǰ 
        ans[now] = tag;
        tag = 3 - tag;//�任tag 
    }
    for (int i = 1; i <= n; i++) cout << ans[i];
    cout << endl;
    return 0;
}
