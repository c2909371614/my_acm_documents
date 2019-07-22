#include <iostream>
using namespace std;
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}

int main()
{
    int t,n,m,a;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        a=m;
        for(int i=1;i<n;i++)
        {
            cin>>m;
            a=a/gcd(a,m)*m;
        }
        cout<<a<<endl;
    }
    return 0;
}
