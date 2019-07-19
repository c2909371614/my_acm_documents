#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string>
#define ll long long 
#define FAST_IO std::ios::sync_with_stdio(false)
using namespace std;
const int MAX = 1e6+5;
const int INF = 0x3f3f3f3f;
int Trees[MAX][26], tot = 1;//trees[i][j],����iΪ�ڵ��ţ�jΪ��֧��Ϣ��a-z)
int p;						//trees[i]j]��¼�ڵ�i��j��ָ֧��Ľڵ�ı��
char str[20];  			   //tot��¼�ڵ��� 

int sum[MAX] ;//��¼��
 
void get_tree(char *str)
{
	int len = strlen(str);
	int p = 1;
	for(int i = 0; i < len; i++)
	{
		int x = str[i]-'a';
		if(Trees[p][x] == 0)
			Trees[p][x] = ++tot;
		
		p = Trees[p][x];
		sum[p]++;//��ǽڵ����ַ������� 
	}
 } 
int search_pre(char *str)
{
	int p = 1;
	int len = strlen(str);
	int s_len = 0;
	for(int i = 0; i < len; i++, s_len = i)
	{ 
		if(Trees[p][str[i]-'a'] != 0)
		{
			p = Trees[p][str[i]-'a'];
		}
		else break;//Trees��û�а���str 
	}
	if(s_len >= len)
		return p;
	return -1; 
 } 
int main()
{

	while(gets(str))
	{
		if(str[0] == '\0')
			break;
		get_tree(str);
	
	}
	char ask[20];
	while(~scanf("%s", ask))
	{
		int index = search_pre(ask);
		if(index >= 0)printf("%d\n",sum[index]);
		else printf("%d\n", 0);
	}
	
 } 
