#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxM=1e5+5;
int myCount(string &a,int n) {
	static int count=0;
	int i;
	
	for(i=0; i<n-1; i++) {
		if(a[i]>a[i+1]) {cout<<"ok";
			a.insert(a[i+1],0);
			a.erase(i+2,1);
			count++;
			cout<<a<<endl;
			break;
		}
	}
	//cout<<i<<endl;
	//cout<<"ok1";
	if(i<n-1)myCount(a,n);
	else return count;
}
int  main() {
	int T;
	int a[maxM],n;
	cin>>T;
	while(T--) {
		//int count=0;
		cin>>n;
		string s;
		for(int i=0; i<n; i++) {
			cin>>a[i];
			s+=a[i]+'0';
		}
		cout<<s<<endl;
		cout<<myCount(s,n)<<endl;
	}
	
}
