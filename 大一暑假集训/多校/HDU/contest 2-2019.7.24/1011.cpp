#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e3+5;
int DP[MAX][MAX];//ÖÜ³¤ 
int max1[MAX][MAX], max2[MAX][MAX];
void init() {
	memset(DP, 0, sizeof(DP));
	memset(max1, 0, sizeof max1);
	memset(max2, 0, sizeof max2);
}
int main() {
	int N, Q;
	int a[MAX];
	while(cin >> N >> Q) {
		init();
		for(int i = 1; i <= N; i++)
			cin >> a[i];
		for(int i = 1; i <= N; i++) {
			max1[i][i+1] = a[i];
			max2[i][i+1] = a[i+1]; 
			for(int j = i + 2; j <= N; j++) {
//				printf("max1[%d][%d]=%d max2[%d][%d]=%d DP[%d][%d]=%d\n",i,j-1,max1[i][j-1],i,j-1,max2[i][j-1],i,j-1,DP[i][j-1]);
				if(max1[i][j-1] + max2[i][j-1] + a[j] > DP[i][j-1] &&
				 abs(max1[i][j-1] - max2[i][j-1]) < a[j] &&
				  a[j] < abs(max1[i][j-1] + max2[i][j-1]) )
				{
					
					DP[i][j] = max1[i][j-1] + max2[i][j-1] + a[j];
					max1[i][j] = max(a[j], max(max1[i][j-1], max2[i][j-1]));
					max2[i][j] = DP[i][j] - max1[i][j] - min(a[j], min(max1[i][j-1], max2[i][j-1]));
//					printf("DP[%d][%d]=%d min=%d\n",i,j,DP[i][j],min(a[j], min(max1[i][j-1], max2[i][j-1])));
				}
				else {
					DP[i][j]   = DP[i][j-1];
					max1[i][j] = max1[i][j-1];
					max2[i][j] = max2[i][j-1];
				}
//				printf("max1[%d][%d]=%d max2[%d][%d]=%d DP[%d][%d]=%d\n",i,j,max1[i][j],i,j,max2[i][j],i,j,DP[i][j]);
			}
		}
		for(int i = 0; i < Q; i++) {
			int x, y;
			cin >> x >> y;
			cout << DP[x][y] << endl; 
		}
	}
}
