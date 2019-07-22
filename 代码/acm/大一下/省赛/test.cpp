#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxM=1e5+5;
int BigNumMod(int BigNum[], int c, int length){
    int ans = 0;
    for(int i = 0; i < length; i++)
        ans = ((ans * 10) + BigNum[i]) % c;
    return ans;
}

int main(){
	
	int a[100];
	memset(a,1,sizeof(a));
	cout<< BigNumMod(a,5,100)<<endl;
	
	
	
	}
