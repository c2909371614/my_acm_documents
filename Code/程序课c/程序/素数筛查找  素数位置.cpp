#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring> 
//#include<bits/stdc++.h> 
using namespace std;

int main()
{
	bool isprime[1000005];
	memset(isprime,true,sizeof(isprime));
	vector<int> prime;
	for(int i=2;i<10005;i++){
		if(isprime[i])prime.push_back(i);
		for(int j=i;j*i<10005;j++)
			isprime[i*j]=false;
	}
	int n;
	while(cin>>n){
		for(int i=n;;i--){ 
			if(n==1){
				cout<<"0"<<endl;
				break;
			} 
			if(n%i==0&&isprime[i]){
				//dou_sort();
				int high=prime.size(),low=0,mid;//cout<<high<<' '<<i<<endl;
				while(high>=low){
					mid=(high+low)/2;
					if(prime[mid]==i)break;
					else if(prime[mid]<i)low=mid+1;
					else high=mid-1;
				}
				//if(high<low)cout<<"invalid\n";
				//return mid;
				cout<<mid+1<<endl;break;
			} 
		} 
	}
}
