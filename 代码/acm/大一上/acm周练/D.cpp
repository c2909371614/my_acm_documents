#include <iostream>
using namespace std;
int gcd(int a,int b)
{
    return b==0?a:gcd(b,a%b);
}

int main()
{
	int a,b;
	while(cin>>a>>b){
		if(a==-1&&b==-1) break;
		if(gcd(a,b)==1) cout<<"YES"<<endl;
		else cout<<"POOR Haha"<<endl;
	}
	return 0;
}
