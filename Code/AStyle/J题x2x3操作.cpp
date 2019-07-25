#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,m;
	while(cin>>n>>m) {
		int count=0,temp;
		if(m%n!=0||((m/n)%3!=0&&(m/n)%2!=0)) {
			if(m==n)cout<<0<<endl;
			else cout<<-1<<endl;

		}

		else {
			temp=m/n;
			while(temp) {
				if(temp%2==0) {
					temp/=2;
					count++;
				} else if(temp%3==0) {
					temp/=3;
					count++;
				} else break;
			}
			if(temp==n)
				cout<<count<<endl;
			else cout<<-1<<endl;
		}

	}
}
