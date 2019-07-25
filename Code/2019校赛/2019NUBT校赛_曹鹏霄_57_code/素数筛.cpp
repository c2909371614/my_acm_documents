#include<bits/stdc++.h>
#define ll long long
const int MAX=1e5+5;
using namespace std;
int prime[MAX];
bool is_prime[MAX];
int select(ll n)
{
	int p=0;
	for(int i=0;i<=n;i++){
		is_prime[i]=true;
	}
	is_prime[0]=is_prime[1]=false;
	for(int i=0;i<=n;i++)
	{
		if(is_prime[i]){
			prime[p++]=i;
			for(int j=i+i;j<+n;j+=i)
			{
				is_prime[j]=false;
			}
		}
	}
	return p;//return ËØÊý¸öÊý 
}
int main()
{
	select(10000);
	for(int i=0;i<50;i++){
		if(i%20==0)cout<<endl;
		cout<<prime[i]<<" ";
		
	}
		
 } 
