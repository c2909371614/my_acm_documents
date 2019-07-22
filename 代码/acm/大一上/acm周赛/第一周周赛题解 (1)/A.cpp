#include <iostream>
#include <cmath>
using namespace std;

bool isprime(long long a)
{
    if(a<=1)
        return 0;
    else
    {
        for(long long i=2;i<=sqrt(a);i++)
        {
            if(a%i==0)
                return 0;
        }
        return 1;
    }
}

int main()
{
	int t;
	cin>>t;
	long long x,y;
	while(t--){
		cin>>x>>y;
		if(x-y==1&&isprime(x+y)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
