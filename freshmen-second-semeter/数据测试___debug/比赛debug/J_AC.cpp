#include<iostream>
#include<cstring>
#include<sstream>
#include<string>
#include<cstdio>
#include<cctype>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<list>
#include<set>
#include<map>
#include<algorithm>
#define fi first
#define se second
#define MP make_pair
#define P pair<int,int>
#define PLL pair<ll,ll>
#define lc (p<<1)
#define rc (p<<1|1)  
#define MID (tree[p].l+tree[p].r)>>1
#define Sca(x) scanf("%d",&x)
#define Sca2(x,y) scanf("%d%d",&x,&y)
#define Sca3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define Scl(x) scanf("%lld",&x)
#define Scl2(x,y) scanf("%lld%lld",&x,&y)
#define Scl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z)
#define Pri(x) printf("%d\n",x)
#define Prl(x) printf("%lld\n",x)
#define For(i,x,y) for(int i=x;i<=y;i++)
#define _For(i,x,y) for(int i=x;i>=y;i--)
#define FAST_IO std::ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define STOP system("pause")
#define ll long long
#include<fstream>
const int INF=0x3f3f3f3f;
const ll INFL=0x3f3f3f3f3f3f3f3f;
const double Pi = acos(-1.0);
using namespace std;
fstream In("data.in",ios::in);//¶ÁÈ¡
fstream Out("AC_data.out",ios::out);//Ð´Èë 
ll qpow(ll a,int k,int MOD) {
	ll sum=1;
	while(k) {
		if(k&1) sum=(sum*a)%MOD;
		a=(a*a)%MOD;
		k>>=1;
	}
	return sum;
}
int main() {
	FAST_IO;
	int T;
	In>>T;
	while(T--) {
		int n,m,k1,k2;
		In>>n>>m>>k1>>k2;
		int mode=qpow(10,k1-1,m)*n%m;
		for(int i = k1;i<=k2;i++) {
			Out << 10LL*mode/m;
			mode=10LL*mode%m;
		}
		Out<<endl;
	}
	Out.close();
	In.close();
}
