#include<iostream>
#include<set>
#include<algorithm> 
#include<string.h>
using namespace std;

int a[30];
struct node{
	int num;
	int sum;
}b[110];
set<int> t;

int cmp(node x,node y){
	if(x.sum==y.sum) return x.num<y.num;
	else return x.sum>y.sum;
}

int main(){
	int q;
	cin>>q;
	while(q--){
		t.clear();
		int n,m;
		memset(b,0,sizeof(b)); 
		cin>>n>>m;
		for(int i=0;i<n+m;i++){
			cin>>a[i];
			b[a[i]].sum++;
			b[a[i]].num=a[i];
			t.insert(a[i]);
		}
		sort(b,b+110,cmp);
		if(b[0].sum==b[1].sum){
			if(b[0].num<b[1].num){
				b[1].num=b[0].num;
			}
		}
		int num=1;
		for(set<int>::iterator it=t.begin();it!=t.end();it++){
			if(*it==b[1].num){
				cout<<num<<endl;
			}else num++;
		}
	}	 
	return 0;
}
