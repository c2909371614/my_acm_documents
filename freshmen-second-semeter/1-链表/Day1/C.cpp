#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;

long long n, m;

int main() {
    cin >> n >> m;
    long long mn = max(0ll, n - m * 2), mx = 0;
    if (m <= 1) {
        cout << mn << ' ' << mn << endl;
        return 0;
    }
    long long num = 0;
    for (int i = 2; i <= n; i++) {
        num += i - 1;
        if (num >= m) {
            mx = n - i;
            break;
        }
    }
    cout << mn << ' ' << mx << endl;
    return 0;
}