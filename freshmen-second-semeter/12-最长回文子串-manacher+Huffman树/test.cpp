#include<bits/stdc++.h>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;

const int MAX = 2e5 + 5;
const int INF = (1 << 30) - 1 + (1 << 30);
char str[MAX];
int p[2*MAX];
char ss[2*MAX];//处理后的字符 
int index[2*MAX];//记录长度 
int id;//用于记录回文中心 
int len;
int Manacher()
{
	ss[0] = '$';
	ss[1] = '#';
	len = strlen(str);//长度获取 
	for(int i = 0; i < len; i++)
	{
		ss[2*i+2] = str[i];
		ss[2*i+3] = '#';
	 } 
//	 cout << ss << endl; 
	len = len*2 + 2; 
	ss[len] = '\0';
	int MAXL = 0, id = 0;
	memset(p, 0, sizeof(p));//对p初始化 
	for(int i = 0; i < len; i++)
	{
		if(p[id] + id > i)//i扫描在回文子串的内部 
			p[i] = min(p[2*id-i], p[id]+id-i);
		else p[i] = 1;
	//	cout << "内部：" << i << "-" << p[i] << endl;
		while(ss[i+p[i]]  == ss[i-p[i]])
			p[i]++;
	//	cout << i << "-" << p[i] << endl; 
		if(p[i]+i > p[id]+id)
			id = i;
		if(p[i] - 1 > MAXL)
			MAXL = p[i] - 1;
	}
	return MAXL;
}
int main()
{
	while(gets(str))
	{
		if(str[0] == '\0')
			continue;
			//cout << str << endl;
//		memset(p, 0, sizeof(p));
		cout << Manacher() << endl; 
	}
}
