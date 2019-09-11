#include<bits/stdc++.h>
using namespace std;
int main(){
	for(int i = 1; i < 10; i++){
		for(int j = 1; j < 10; j++){
			printf("%d^%d-%d ", i, j, i^j);
		}
		cout << endl;
	}
} 
