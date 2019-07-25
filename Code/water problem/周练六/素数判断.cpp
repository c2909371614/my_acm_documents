#include<iostream >
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
//#include<bits/stdc++.h> 
using namespace std;
int main()
{
	bool isprime[10005];
	//memset(isprime,true,sizeof(isprime));
	for(int i=0;i<10005;i++) 
		isprime[i]=true;
	vector<int> prime;
	for(int i=2;i<10005;i++){
		if(isprime[i])prime.push_back(i);
		for(int j=i;j*i<10005;j++)
			isprime[i*j]=false;
	}
	int x,y;
	while(cin>>x>>y){
		bool flag=true;
		if(x==0&&y==0)break;
		for(int i=x;i<=y;i++)
			if(!isprime[i*i+i+41])flag=false;
		flag?printf("OK\n"):printf("Sorry\n"); 
	}	
}
