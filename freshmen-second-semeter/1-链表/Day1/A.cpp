#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

int n, m;
int u, v;
int deg[N], num[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        deg[u]++, deg[v]++;
    }
    for (int i = 1; i <= n; i++) {
        num[deg[i]]++;
    }
    if (num[1] == 2 && num[2] == n - 2) {
        cout << "bus topology" << endl;
    }
    else if (num[n - 1] == 1 && num[1] == n - 1) {
        cout << "star topology" << endl;
    }
    else if (num[2] == n) {
        cout << "ring topology" << endl;
    }
    else {
        cout << "unknown topology" << endl;
    }
    return 0;
}