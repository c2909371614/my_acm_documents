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
string str[8]={"111","110","101","100","011","010","001","000"};//1�����ɫ0�����ɫ
int mp[10000][10000];
void make(int a[],int n){
	mem0(mp);
	
	map<string,int> m;//������Ĺ�����ƥ�䣬��111ƥ������ĵ�һ����������1��111�·���Ϊ��
	for(int i=0;i<8;i++) m[str[i]]=a[i];//��Ӧ�������
	int mid = n ;
	mp[0][mid]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<2*n;j++){
			char temp1,temp2=(char)mp[i-1][j]+'0',temp3;
			if(j==0) temp1='0';
			else temp1=(char)mp[i-1][j-1]+'0';
			if(j==2*n-1) temp3='0';
			else temp3=(char)mp[i-1][j+1]+'0';//��Ե����������
			char flag[3];
			flag[0]=temp1;
			flag[1]=temp2;
			flag[2]=temp3;
			mp[i][j]=m[flag];//��������Ĺ���ȷ����һ�е�ֵ
		}
	}
}
int main(){
	int n;
	int a[8];
	cout << "����õ��������δ�С��"; 
	cin>>n;//�����������ж���
	for(int i=0;i<8;i++){
		cout<<str[i]<<"�˴�����Ϊ��";
		cin>>a[i];//�����Ӧ����
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
