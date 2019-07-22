#include <iostream>
using namespace std;
#define ll long long

int main()
{
	ll n;
	cin>>n;
	for(ll i=2;i*i<=n;i++){
		while(n%(i*i)==0) n/=i;
	}
	cout<<n<<endl;
	return 0;
}
