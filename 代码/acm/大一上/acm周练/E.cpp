#include <iostream>
using namespace std;
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}
int main()
{
    int t;
    cin>>t;
    int a,b,c,d;
    int e,f,e1,f1;
    while(t--)
    {
        cin>>a>>b>>c>>d;
        e=a*d+b*c;
        f=b*d;
        e1=e/gcd(e,f);
        f1=f/gcd(e,f);
        cout<<e1<<" "<<f1<<endl;
    }
    return 0;
}
