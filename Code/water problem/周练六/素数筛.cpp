#include<iostream >
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring> 
//#include<bits/stdc++.h> 
using namespace std;
int main()
{
	bool isprime[10005];
	memset(isprime,true,sizeof(isprime));
	vector<int> prime;
	for(int i=2;i<10005;i++){
		if(isprime[i])prime.push_back(i);
		for(int j=i;j*i<10005;j++)
			isprime[i*j]=false;
	}
	int n,count;
	while(cin>>n){
		count=0;
		for(int i=0;prime[i]<=n/2;i++)
			for(int j=i;prime[j]<n;j++){
				if(n==prime[i]+prime[j]){
					count++;/*printf("i=%d j=%d\n",i,j);*/break;
				}
			}
		cout<<count<<endl;
	}
//	for(int i=0;i<prime.size();i++)
//		cout<<prime[i]<<' ';
 } 
