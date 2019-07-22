#include <iostream>
using namespace std;
int a[15],b[15];

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i]==b[j]){
				cout<<a[i]<<" ";
				break;
			}
		}
	}
	return 0;
}
