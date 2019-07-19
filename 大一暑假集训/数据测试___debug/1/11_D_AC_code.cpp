#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxx=200005;
int s[maxx],mx[maxx*4];
void pushup(int rt)
{
    mx[rt]=max(mx[rt*2],mx[rt*2+1]);   //求最大值
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        mx[rt]=s[l];
        return ;
    }
    int mid=(l+r)/2;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    pushup(rt);
}
int query(int L,int R,int l,int r,int rt)
{
    if(L<=l && R>=r) return mx[rt];
    int mid=(l+r)/2;
    int ret=0;
    if(L<=mid)  ret=max(ret,query(L,R,l,mid,rt*2));
    if(R>mid)   ret=max(ret,query(L,R,mid+1,r,rt*2+1));
    return ret;
}
void update(int L,int s,int l,int r,int rt)
{
    if(l==r)
    {
        mx[rt]=s;
        return ;
    }
    int mid=(l+r)/2;
    if(L<=mid)  update(L,s,l,mid,rt*2);
    else        update(L,s,mid+1,r,rt*2+1);
    pushup(rt);
}
fstream In("data.in",ios::in);//读取
fstream Out("my_data.out",ios::out);//写入#include<iostream>
int main()
{
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        for(int i=1; i<=n; i++)  scanf("%d",&s[i]);
        build(1,n,1);
        int a,b;
        char ch;
        while(m--)
        {
            scanf(" %c%d%d",&ch,&a,&b);
            if(ch=='Q')  printf("%d\n",query(a,b,1,n,1));
            else         update(a,b,1,n,1);
        }
    }
    return 0;
}
