#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
// #include<map>
#include<cmath>
#include<list>
#include<bits/stdc++.h>
#define ll long long
#define N 10010
#define pb push_back
#define Sca(a) scanf("%d",&a)
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define Scal(a) scanf("%ld",&a)
#define Scall(a) scanf("%lld",&a)
#define Pri(a) printf("%d",a)
#define Pril(a) printf("%ld",a)
#define Prill(a) printf("%lld",a)
#define FAST_IO ios::sync_with_stdio(false)
using namespace std;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
const double pi = 3.141592653;
using namespace std;
template <class T>void tomax(T&a, T b) {
    a = max(a, b);
}
template <class T>void tomin(T&a, T b) {
    a = min(a, b);
}
int f[100005],num[100005];
void init(){
    for(int i=0;i<100005;i++){
        f[i]=i,num[i]=1;
    }
}
int find(int k){
    if(f[k]==k) return k;
    return f[k]=find(f[k]);
}
int tot=0;
int add(int a,int b){
    int xx=find(a),yy=find(b);
    if(xx!=yy){
        num[yy]+=num[xx];//联通数量 
        num[xx]=0;
        f[xx]=yy;
    }
}
struct
{
    int a,b;
}json[100005];
int ans[100005];
int main(){
    // FAST_IO;
    int n,m;
    scanf("%d%d",&n,&m);
    init();
    for(int i=0;i<m;i++){
        scanf("%d%d",&json[i].a,&json[i].b);
    }
    int cnt=n*(n-1)/2;
    ans[m]=cnt;
    for(int i=m-1;i>=0;i--){
        int xx=find(json[i].a),yy=find(json[i].b);
        if(xx != yy){
            ans[i]=ans[i+1]-num[xx]*num[yy];
            add(json[i].a,json[i].b);   
        }
        else ans[i]=ans[i+1];       
    }
    for(int i=1;i<=m;i++) Pri(ans[i]),printf("\n");
}
