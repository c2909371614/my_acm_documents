#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxM=1e5+5;
int main(){
	int T;
	int n,m;
	int a[maxM],odd_a=0,even_a=0,b[maxM],odd_b=0,even_b=0;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]&1!=0)
			odd_a++;
		else even_a++;
	}
	for(int i=0;i<m;i++){
		cin>>b[i];
		if(b[i]&1!=0)
			odd_b++;
		else even_b++;
	}
	//cout<< odd_a<<even_b<<odd_b<<even_a<<endl;
	cout<<(min(odd_a,even_b)+min(odd_b,even_a))<<endl;
} 
