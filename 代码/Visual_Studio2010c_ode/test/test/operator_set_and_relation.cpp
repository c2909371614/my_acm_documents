#include"Relation.h"
#include "stdafx.h"
string limit(Relation_ship &R,mySet &A)
{
	Relation_ship R_A;//cout<<"ok"<<endl;
	for(int i=0;i<R.first.size();i++)
	{
		if(A.element.find(R.first[i])!=string::npos)//�ҵ�˵��Ϊ���Ƶ��� 
		{
			R_A.first+=R.first[i];
			R_A.second+=R.second[i];
			
		}		
	}
	return R_A.toRelaString();
}
string mirror(const Relation_ship &R,const mySet &A)
{
	mySet Mirror;//cout<<"ok"<<endl;
	for(int i=0;i<R.first.size();i++)
	{
		if(A.element.find(R.first[i])!=string::npos)//�ҵ�˵��Ϊ�� 
		{
			Mirror.element+=R.second[i];	//�ҵ���ֵ�����񼯺�Ԫ�� 
		}		
	}
	return toSetString(Mirror.getEle());
 } 
 bool isA_Relation(Relation_ship &R,mySet &A) 
 {
 	if(R.first.size()==0)return true;//�ռ�Ϊ�κμ����ϵĶ�Ԫ��ϵ
 	mySet R_set(R.fld());//��ȡ��ϵ���򼯺� 
 	cout<<"fld:"<<R_set.getEle()<<" A:"<<A.getEle()<<endl;//test
 	if(A.isSubSet(R_set))return true;//��ϵ�����Ƿ�Ϊ����A���Ӽ�,��������A�ϵĶ�Ԫ��ϵ 
	return false;
 }
 string set_smaller_re(Relation_ship &R,mySet &A)
 {
 	R.get_Smaller(A.getEle());
 	//cout<<A.getEle()<<endl;
 	return R.toRelaString();
 }
 string set_equal_re(Relation_ship &R,mySet &A)
 {
 	R.get_Ia(A.getEle());
 	return R.toRelaString();
 }


