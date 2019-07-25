#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
using namespace std;
int const MAX=1e5+5;
vector<int> ver[MAX],edge[MAX];
int node[MAX];
void add(int x,int y,int z)
{
	ver[x].push_back(y);
	edge[x].push_back(z);
}
int main()
{
	int T;
	int n,m;
	int x,y; 
	cin>>n>>m;
	memset(node,0,sizeof(node));
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		ver[x].push_back(y);
		ver[y].push_back(x);
		node[x]++;
		node[y]++;
	}
	int max=0;
	int max_num=0;
	bool star=true,ring=true,bus=true;
	for(int i=1;i<=n;i++)
	{
		if(node[i]>max)
			max=node[i];
	}
	for(int i=1;i<=n;i++){
		if(node[i]==max)
			max_num++;
		else {
			ring=false;
			if(node[i]!=1){
				bus=false;
				star=false;
			}		
		}
	}
	//cout<<"sum"<<sum<<endl; 
	if(max_num==1&&max==n-1&&star)
		cout<<"star topology"<<endl;
	else if(max_num==n&&max==2&&ring)
		cout<<"ring topology"<<endl;
	else if (max_num==n-2&&max==2&&bus)
		cout<<"bus topology"<<endl;
	else cout<<"unknown topology"<<endl;
 } 
