#include <iostream>
using namespace std;
int gcd(int x,int y)
{
    return y==0?x:gcd(y,x%y);
}

int main()
{
	int a,b;
	while(cin>>a>>b){
		cout<<a/gcd(a,b)*b<<endl;
	}
	return 0;
}
