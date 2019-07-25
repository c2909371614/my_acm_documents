#include <bits/stdc++.h>
#define rep(x,a,b) for(int x=a;x<=b;x++)
#define times(x) for(int cas=1,tms=(x);cas<=tms;cas++)
using namespace std;
const int N = 1e5 + 5;
typedef pair<int, int> pint;
 
int n, k;
int a[N], l[N], r[N];
set<pint>st;
 
int main() {
    scanf("%d%d",&n,&k);
    rep(i,1,n) scanf("%d", &a[i]);
    n--;
    rep(i,1,n) a[i] = a[i+1] - a[i];
    rep(i,1,n) st.insert(make_pair(a[i], i));
    rep(i,1,n+1) l[i] = i-1;
    rep(i,0,n) r[i] = i+1;
    int ans = 0;
    times(k){
        pint t = *st.begin(); st.erase(st.begin());
        int x = t.first, p = t.second;
        ans += x;
        int le = 0x3f3f3f3f, ri = 0x3f3f3f3f;
        if(l[p] != 0){
            le = a[l[p]];
            st.erase(make_pair(le, l[p]));
            r[l[l[p]]] = p;
            l[p] = l[l[p]];
        }
        if(r[p] != n+1){
            ri = a[r[p]];
            st.erase(make_pair(ri, r[p]));
            l[r[r[p]]] = p;
            r[p] = r[r[p]];
        }
        st.insert(make_pair(le + ri - x, p));
        a[p] = le + ri - x;
    }
    printf("%d\n", ans);
    return 0;
}