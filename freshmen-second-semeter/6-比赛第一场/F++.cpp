#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int MAX = 1e5 + 5;

int num[55][55];
char pic[55][55];
int vis[55][55];
int n, m;
bool flag = true;
bool dfs(int x, int y) { //dfsÕÒ»·
	vis[x][y] == 1;
	if(pic[x-1][y] == '#') {
		if(vis[x-1][y] == 2)
			return true;
		if(!vis[x-1][y])dfs(x-1,y);
	}
	if(pic[x+1][y] == '#') {
		if(vis[x+1][y] == 2)
			return true;
		if(!vis[x+1][y])dfs(x+1, y);
	}
	if(pic[x][y-1] == '#') {

		if(vis[x][y-1] == 2)
			return true;
		if(!vis[x][y-1])dfs(x, y-1);
	}
	if(pic[x][y+1] == '#') {
		if(vis[x][y+1] == 2)
			return true;
		if(!vis[x][y+1])dfs(x,y+1);
	}
	
	return false;
}
int main() {
	memset(pic, '.', sizeof(pic));
	memset(vis, false, sizeof(vis));
	memset(num, 0, sizeof(num));
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			cin >> pic[i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++) {
			if(pic[i][j] == '#') {
				if(pic[i-1][j] == '#')
					if(pic[i+1][j] == '#') {
						if(pic[i+1][j-1] != '#' && pic[i+1][j+1] !='#' &&
						        pic[i-1][j-1] != '#' && pic[i-1][j+1] != '#') {
							memset(vis, 0, sizeof(vis));
							vis[i][j] = 2;

							if(!dfs(i,j)) {cout <<"ok"<<endl;
								cout << 1 << endl;
								return 0;
							}
						}//cout <<"ok"<<endl;
					}cout <<"ok"<<endl;
				if(pic[i][j+1] == '#')
					if(pic[i][j-1] == '#') {
						if(pic[i+1][j-1] != '#' && pic[i+1][j+1] !='#' &&
						        pic[i-1][j-1] != '#' && pic[i-1][j+1] != '#') {
							memset(vis, 0, sizeof(vis));
							vis[i][j] = 2;
							
							if(!dfs(i,j)) {
								cout << 1 << endl;
								return 0;
							}
						}
					}
				flag = false;
			}
		}
//	int Min = MAX;
	int sum = 0;cout <<"ok"<<endl;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(pic[i][j] == '#'){
				sum += num[i][j];
//				cout << i << "-" << j << " " << num[i][j] << " " << endl;
			}
	sum == 0?cout << -1 << endl:cout << 2 << endl;
}

