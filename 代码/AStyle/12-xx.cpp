#include<bits/stdc++.h>
using namespace std;
template<typename T>
T* sumPoint(T x[],T y[],T z[],int n) {
	int *ans;
	for(int i=0; i<n; i++)
		ans[i]+=x[i]+y[i]+z[i];
	for(int i=0; i<n; i++)
		cout<<ans[i]<<" ";
	return ans;
}
int main() {
	int n;
	cin>>n;
	int*x=new int[n];
	int*y=new int[n];
	int*z=new int[n];
	int* ans;
	for(int i=0; i<n; i++)
		cin>>x[i];
	for(int i=0; i<n; i++)
		cin>>y[i];
	if(n==3)
		for(int i=0; i<n; i++)
			cin>>z[i];
	ans=sumPoint(x,y,z,n);
	for(int i=0; i<n; i++)
		cout<<ans[i]<<" ";
}
