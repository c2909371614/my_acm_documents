#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;

int n,m,k;
queue<int>q;
bool func(int n)
{
    if(n%k==0)return true;
    while(n)
    {
        if(n%10==k)return true;
        n/=10;
    }
    return false;
}

int main(){

	int t;
	cin>>t;
	while(t--){
		cin>>n>>m>>k;
		while(!q.empty()) q.pop();
	    for(int i=1;i<=n;i++)
	    {
	        q.push(i);
	    }
	    int t;
	    while(q.size()>1)
	    {
	        t=q.front();
	        q.pop();
	        if(!func(m++))
	        {
	            q.push(t);
	        }
	    }
	    cout<<q.front()<<endl;
	}
    return 0;
}
