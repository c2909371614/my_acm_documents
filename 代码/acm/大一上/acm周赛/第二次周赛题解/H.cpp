#include<iostream>
using namespace std;
int main()
{
	long long  t,n,x;
	long long ans;
	while (cin>>n){
		ans=1;
		for (int i=0;i<n;i++){
			cin>>x;
			if (x%2==1)
				ans*=x;
		}
		cout<<ans<<endl;
	}
	return 0;
}
