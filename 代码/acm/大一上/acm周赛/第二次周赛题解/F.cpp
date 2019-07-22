#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int maxn=2500+10;
struct nod
{
    int a;
    int b;
};
nod cow[maxn],s[maxn];
bool cmp1(nod x,nod y)
{
    return x.b==y.b?x.a<y.a:x.b<y.b;
}
bool cmp2(nod x,nod y)
{
    return x.a<y.a;
}
int main()
{
    int c,l;
    int m,n;
    while(scanf("%d%d",&c,&l)!=EOF)
    {
        for(int i=0;i<c;i++)
        {
            scanf("%d%d",&cow[i].a,&cow[i].b);
        }
        for(int i=0;i<l;i++)
        {
            scanf("%d%d",&s[i].a,&s[i].b);
        }
        sort(cow,cow+c,cmp1);
        sort(s,s+l,cmp2);
        int cut=0;
        for(int i=0;i<c;i++)
        {
            for(int j=0;j<l;j++)
            {
                    if(s[j].a>=cow[i].a&&s[j].a<=cow[i].b&&s[j].b>0)
                    {
                        cut++;
                        s[j].b--;
                        break;
                    }
            }
        }
        cout<<cut<<endl;
    }
    system("pause") ;
}
