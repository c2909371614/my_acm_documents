#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;
set<string> dict;//����set�� 
 
int main()
{
	string s,buf;
	while(cin>>s && s !="#")  
	{
		for(int i=0;i<s.length();i++)
		{
			if(isalpha(s[i]))//�ж��Ƿ�Ϊ���� 
			    s[i]=tolower(s[i]);//ͳһΪСд 
			else
			    s[i]=' '; 
		} 
		stringstream ss(s);//���ַ���s�������� 
		while(ss>>buf)//�����еĵ��ʵ�����buf��ʱ��� 
		dict.insert(buf);/*��stringstream����ʽ�����ʵ���set�У���������ų��ո���߷��ŵĸ��� */
	}
	for(set<string>::iterator it=dict.begin();it!=dict.end();it++)/*ʹ�õ��������set�еĵ��� */
	    cout<<*it<<endl;
}

