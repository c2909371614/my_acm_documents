#include<bits/stdc++.h>
using namespace std;
int const MAX=105;
char matrix[MAX][MAX];//计入数据
char bool_matrix[MAX][MAX];
int n;//nxn matrix
void turn_begin() {//cout<<"ok"<<endl;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) {
			if(matrix[i][j]=='.') {
				if(i!=0&&matrix[i-1][j]=='#')matrix[i-1][j]='+';
				if(i!=n-1&&matrix[i+1][j]=='#')matrix[i+1][j]='+';
				if(j!=0&&matrix[i][j-1]=='#')matrix[i][j-1]='+';
				if(j!=n-1&&matrix[i][j+1]=='#')matrix[i][j+1]='+';
			}
		}
}
void copy_matrix() {
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			bool_matrix[i][j]=matrix[i][j];

}
void print() {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++)
			cout<<bool_matrix[i][j];
		cout<<endl;
	}
}
void dfs(int m,int n) {
	bool_matrix[m][n]='+';
	if(bool_matrix[m-1][n]=='#')dfs(m-1,n);
	if(bool_matrix[m+1][n]=='#')dfs(m+1,n);
	if(bool_matrix[m][n-1]=='#')dfs(m,n-1);
	if(bool_matrix[m][n+1]=='#')dfs(m,n+1);
}
void dfs_change(int m,int n) {
	bool_matrix[m][n]='*';
	if(bool_matrix[m-1][n]=='#'||bool_matrix[m-1][n]=='+')dfs_change(m-1,n);
	if(bool_matrix[m+1][n]=='#'||bool_matrix[m+1][n]=='+')dfs_change(m+1,n);
	if(bool_matrix[m][n-1]=='#'||bool_matrix[m][n-1]=='+')dfs_change(m,n-1);
	if(bool_matrix[m][n+1]=='#'||bool_matrix[m][n+1]=='+')dfs_change(m,n+1);
}
int ALL_dfs_change() {
	int ans=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) {
			if(bool_matrix[i][j]=='#') {
				ans++;
				//cout<<ans<<endl;
				dfs_change(i,j);
			}
		}
	//	cout<<ans<<endl;
	return ans;
}
int ALL_dfs() {
	int ans=0;
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++) {
			if(bool_matrix[i][j]=='#') {
				ans++;
				//cout<<ans<<endl;
				dfs(i,j);
			}
		}
	return ans;
}
int main() {
	int T;
	cin>>T;
	while(T--) {
		cin>>n;
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin>>matrix[i][j];
		copy_matrix();//先复制matrix
		//print();
		int origin=ALL_dfs();//计算出初始未感染的组数
		//cout<<origin<<endl;//cout<<"ok"<<endl;
		turn_begin();//感染
		copy_matrix();

		int change=ALL_dfs_change();//计算感染后的组数
		//print();
		cout<<origin-change<<endl;
	}
}
