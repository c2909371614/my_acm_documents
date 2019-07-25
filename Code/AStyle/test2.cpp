#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	int a[n];
	while(cin>>n) {
		for(int i=0; i<n; i++)
			a[i]=1;
		for(int i=0; i<n; i++) {
			if(i%20==0)cout<<endl;
			cout<<a[i]<<" ";

		}
	};
}
