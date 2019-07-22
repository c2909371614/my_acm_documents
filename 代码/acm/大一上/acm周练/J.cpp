#include <iostream>
using namespace std;
const int N = 1e6 + 5;
int prime[N];
int pos[N];
int tot=1;
void init() {
    for(int i=2;i<N;i++) {
        if(prime[i]==0) {
            pos[i]=tot++;
            for(int j=i;j<N;j+=i) prime[j]=i;
        }
    }
}

int main()
{
	int n;
	init();
	while(scanf("%d",&n)!=EOF){
		printf("%d\n",pos[prime[n]]);
	}
	return 0;
}
