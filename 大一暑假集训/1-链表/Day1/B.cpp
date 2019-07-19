#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
 
int n;
int fa[N];
 
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> fa[i];
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int tmp = 1;
        int t = fa[i];
        while (t != -1) {
            t = fa[t];
            tmp++;
        }
        ans = max(tmp, ans);
    }
    cout << ans << endl;
    return 0;
}