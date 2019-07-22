#include <iostream>
using namespace std;
const int N = 1e7 + 5;
bool isprime[N];
int prime[N];
int ans[1005];
int tot=1;
void init(){
    for(int i=2;i<N;i++){
        isprime[i] = true;
    }
    for(int i=2;i<N;i++){
        if(isprime[i]){
            for(int j=2*i;j<N;j=j+i){
                isprime[j]=false;
            }
        }
    }
    for(int i=2;i<N;i++){
        if(isprime[i]){
            prime[tot] = i;
            tot++;
        }
    }
}

bool huiwen(int n)
{
	int x=0,nn=n;
	while(n){
		x=x*10+n%10;
		n/=10;
	}
	return x==nn;
}

int main()
{
	int a,b;
	int k=0;
	init();
	for(int i=1;i<tot;i++){
		if(huiwen(prime[i])){
			ans[k++]=prime[i];
		}
	}
	while(cin>>a>>b){
		for(int i=0;i<=k;i++){
			if(a<=ans[i]&&ans[i]<=b) cout<<ans[i]<<endl;
			else if(ans[i]>b) break;
		}
		cout<<endl;
	}
	return 0;
}
