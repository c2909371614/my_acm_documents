#include<iostream>
#include<algorithm>
#include<cstdio> 
using namespace std;

int main()
{
	int t,n,m,count;
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%d%d",&n,&m);
		count=1;
		if(m>(1+n)*n/2) printf("-1\n");
		else{
			while(m>n){
				m-=n;
				n--;
				count++;
			}
		printf("%d\n",count);	
		}
	}
	return 0;
}
