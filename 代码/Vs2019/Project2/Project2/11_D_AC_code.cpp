#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<fstream>
using namespace std;
fstream In("data.in",ios::in);//��ȡ
fstream Out("AC_data.out",ios::out);//д�� 
char list[1005][25];
struct node
{
	int count;
	node *childs[26];
	node()
	{
		count=0;
		int i;
		for(i=0;i<26;i++)
		childs[i]=NULL;
	}
};
node *root=new node;
node *current,*newnode;
void insert(char *str)
{
	int i,m;
	current=root;
	for(i=0;i<strlen(str);i++)
	{
		m=str[i]-'a';
		if(current->childs[m]!=NULL)
		{
			current=current->childs[m];
			++(current->count);
		}
		else
		{
			newnode=new node;
			++(newnode->count);
			current->childs[m]=newnode;
			current=newnode;
		}
	}
}
void search(char *str)
{
	int i,m;
	char ans[25];
	current=root;
	for(i=0;i<strlen(str);i++)
	{
		m=str[i]-'a';
        current=current->childs[m];
		ans[i]=str[i];
		ans[i+1]='\0';
		if(current->count==1)    //����Ψһ��ʾ���ַ�����ǰ׺
		{
			//printf("%s %s\n",str,ans);
			Out << str << " " << ans << endl;//�� 
			return;
		}
	}
//	printf("%s %s\n",str,ans);  // ����������ַ���
	Out << str << " " << ans << endl;//�� 
}
int main()
{
	int i,t=0;
	while(/*scanf("%s",list[t])!=EOF*/In >> list[t])
	{
		insert(list[t]);
		t++;
	}
	for(i=0;i<t;i++)
		search(list[i]);
	In.close();//���ļ� 
	Out.close();//���ļ� 
	return 0;
}
