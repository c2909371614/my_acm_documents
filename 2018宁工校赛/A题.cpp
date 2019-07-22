#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxM= 1e5+5;
int main(){
	int t;
	cin>>t;
	while(t--){
		int a1,a2,b1,b2;
		cin>>a1>>a2>>b1>>b2;
		if(a1*a2>b1*b2){
			cout<<"Idiot"<<endl;
		}
		else cout<<"Foolish"<<endl;
	}
	return 0;
}
