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
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		node[i]=x;	
	}
	int temp_max,max=0;
	for(int i=1;i<=n;i++){
		temp_max=0;
		for(int j=i;j<=n;){
			if(node[j]!=-1){
				temp_max++;
				j=node[j];
			}
			else break;
		}
		if(temp_max>max)
			max=temp_max;
	}
	cout<<max+1<<endl;
 } 
