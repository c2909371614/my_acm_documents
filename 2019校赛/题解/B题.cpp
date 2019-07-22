#include <cstdio>
#include <algorithm>
#include<iostream>
using namespace std;
int t,n,l,rec,s[1005],f[1005][1005][2];
int main() {
	scanf("%d",&t);
	while(t--)    {
		scanf("%d%d",&n,&l);
		for(int i=1; i<=n; i++)scanf("%d",&s[i]);
		s[++n]=l;
		sort(s+1,s+1+n);
		for(int i=1; i<=n; i++)
			if(s[i]==l)rec=l,f[i][i][0]=f[i][i][1]=0;
			else f[i][i][0]=f[i][i][1]=0x3fffffff;
		for(int i=rec; i; i--){
			for(int j=i+1; j<=n; j++) {
				f[i][j][0]=min(f[i+1][j][0]+(s[i+1]-s[i])*(n-j+i),f[i+1][j][1 ]+(s[j]-s[i])*(n-j+i));
				f[i][j][1]=min(f[i][j-1][1]+(s[j]-s[j-1])*(n-j+i),f[i][j-1][0 ]+(s[j]-s[i])*(n-j+i));
				cout<<min(f[i][j][0],f[i][j][1])<<" ";
			}
			cout<<endl;
		}
			
		printf("%d\n",min(f[1][n][0],f[1][n][1]));
	}
} 
