#include"Relation.h" 
#include "stdafx.h"
void Relation_ship::get_divide(string s)
{
	first="";
	second="";
	int count=0;
	for(int i=0;i<s.size();i++){
		for(int j=0;j<s.size();j++){
			if((s[j]-'0')%(s[i]-'0')==0){
				this->first+=s[i];
				this->second+=s[j];
			}
		}
	}
}
void Relation_ship::get_Con(string set[100])
{
	int num=0;//num���ڵó�set�������Ч���� 
	while(set[num].size()>0)
	{
		if(set[num]!="@")sort(set[num].begin(),set[num].end());//@����ռ� 
		cout<<set[num]<<endl;
		num++;
	}
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++)
		{//������Ѱ�ҵ�˵��Ϊ�Ӽ������ 
			if((set[i]=="@")||(set[j].find(set[i].c_str())!=string::npos)){//�ռ��ض������� 
				first_set[index]=toSetString(set[i]);
				second_set[index]=toSetString(set[j]);
				index++;
			}
		}
	}
	//cout<<index<<endl;
}
Relation_ship Relation_ship::get_inverse()
{
	Relation_ship rela;
	rela.setFirst_Second(second,first);
	return rela;
 } 
