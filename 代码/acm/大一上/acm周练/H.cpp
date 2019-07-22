#include <iostream>
using namespace std;
bool prime(int a)
{
    if(a<=1) return 0;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}

int main()
{
	int n;
	while(cin>>n){
		int ans=0;
		for(int i=1;i<=n/2;i++){
			if(prime(i)&&prime(n-i)) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
