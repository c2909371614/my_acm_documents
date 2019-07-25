#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int UINT;
#define FAST_IO std::ios::sync_with_stdio(false),std::cin.tie(0),std::cout.tie(0)
struct node {
    int ele, w;
    bool operator<(const node &x) const {
        return w > x.w;
    }
    node(const int &x = 0, const int &w = 0) : ele(x),w(w) {}
};

int main(void)
{
    FAST_IO;
    int t;
    int nn = 0;
    while (cin >> t && t != 0)
    {
        nn++;
        cout << "Case #" << nn << ":" << endl;
        list<node> A, B;
        int cnt = 0;
        for (int i = 0; i < t; i++)
        {
            string opt, r, r2;
            cin >> opt >> r;
            if (opt == "push") {
                int x;
                cin >> x;
                if (r == "A") {
                    A.push_front(node(x, cnt++));
                } else {
                    B.push_front(node(x, cnt++));
                }
            } else if (opt == "pop") {
                if (r == "A"){
                    cout << A.front().ele << endl;
                    A.pop_front();
                } else {
                    cout << B.front().ele << endl;
                    B.pop_front();
                }
            } else if (opt == "merge"){
                cin >> r2;
                if (r == "A"){
                    A.merge(B);
                    B.clear();
                } else {
                    B.merge(A);
                    A.clear();
                }
            }
        }
    }

    // system("pause");
    return 0;
}
//STL list solution from yuming (chao xuan xue)