#include<iostream>
#include<algorithm>
#include<queue>
#include<stack>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<cmath>
#include<list>
#define ll long long
#define N 100010
#define pb push_back
#define Sca(a) scanf("%d",&a)
#define mem0(a) memset(a,0,sizeof(a))
#define mem1(a) memset(a,-1,sizeof(a))
#define Scal(a) scanf("%ld",&a)
#define Scall(a) scanf("%lld",&a)
#define Pri(a) printf("%d",a)
#define Pril(a) printf("%ld",a)
#define Prill(a) printf("%lld",a)
#define FAST_IO ios::sync_with_stdio(false)
using namespace std;
const int INF = 0x3f3f3f3f;
const ll INFL = 0x3f3f3f3f3f3f3f3f;
using namespace std;
template <class T>void tomax(T&a, T b) {
	a = max(a, b);
}
template <class T>void tomin(T&a, T b) {
	a = min(a, b);
}
string str[8]={"111","110","101","100","011","010","001","000"};//1代表黑色0代表白色
int mp[10000][10000];
void make(int a[],int n){
	mem0(mp);
	
	map<string,int> m;//与输入的规则做匹配，如111匹配输入的第一个规则，输入1则111下方块为黑
	for(int i=0;i<8;i++) m[str[i]]=a[i];//对应输入规则
	int mid = n ;
	mp[0][mid]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<2*n;j++){
			char temp1,temp2=(char)mp[i-1][j]+'0',temp3;
			if(j==0) temp1='0';
			else temp1=(char)mp[i-1][j-1]+'0';
			if(j==2*n-1) temp3='0';
			else temp3=(char)mp[i-1][j+1]+'0';//边缘处进行特判
			char flag[3];
			flag[0]=temp1;
			flag[1]=temp2;
			flag[2]=temp3;
			mp[i][j]=m[flag];//根据输入的规则确定下一行的值
		}
	}
}
int main(){
	int n;
	int a[8];
	cout << "输入得到的三角形大小："; 
	cin>>n;//输入三角形有多少
	for(int i=0;i<8;i++){
		cout<<str[i]<<"此处规则为：";
		cin>>a[i];//输入对应规则
	}
	make(a,n);
	for(int i=0;i<n;i++){
		for(int j=0;j<2*n;j++)
			// cout<<mp[i][j];
			if(mp[i][j]==1) cout<<"*";
			else cout<<" ";
		cout<<endl;	
	}

}
