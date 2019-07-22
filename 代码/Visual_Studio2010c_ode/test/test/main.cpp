#include"mainHead.h"
#include"Relation.h"
#include "stdafx.h"

//string s1="{1,3,6,7}",s2="1,2,3",s3="{1,2,3}",s4="23",s5="123456",s6="234",s7="14";
//string re1="123",re2="2",re3="345";
string s1,s2,s3,s4,s5,s6,s7; 
string re1,re2,re3;
void get_data()
{
	fstream io("data.txt",ios::in);
	io>>s1>>s2>>s3>>s4>>s5>>s6>>s7;
	io>>re1>>re2>>re3;//���ļ��ж�ȡ��Ϣ��ֵ; 
}

void test_set()
{
	mySet set1(s1),set2(s2),set0,set3(s3);//������������ 
	cout<<"set1=";
	set1.myPrint();
	cout<<"set2=";
	set2.myPrint();
	cout<<"set3=";
	set3.myPrint();
	//set1.Belong();
	mySet sum(set1.sumSet(set2));//�ϼ����� 
	cout<<"set1��set2�ĺϼ�="; 
	sum.myPrint();
	
	cout<<"set1��set2�Ľ���="; 
	mySet sub(set1.subSet(set2));//���ɽ����� 
	sub.myPrint();
	
	cout<<"set1��set2�Ĳ="; 
	mySet diff(set1.DiffSet(set2));//� 
	diff.myPrint();
	cout<<"����Ӽ�����Ϊ:"<<diff.subNum()<<endl;
	
	cout<<"�ռ��ж�set0=@:"; 
	if(set0.isEmpty()==0)//�ж��Ƿ�Ϊ�� 
		cout<<"empty"<<endl;
	else cout<<"no empty"<<endl;
	
	cout<<"set1��set2����Բ��"; 
	mySet set(set1.oppsDiffSet(set2));//��Բ 
	set.myPrint();
	
	cout<<"�ж�set2��set3�Ƿ����"<<endl; 
	if(set2.isEqual(set3))//�ж��Ƿ���� 
		cout<<"equal"<<endl;
	else cout<<"no euqal"<<endl;

 } 
void test_relation()
{
	cout<<endl<<"��ϵ����"<<endl; 
	Relation_ship rela(re1,re2);//��ʼ������AxB 
	
	cout<<"��Ԫ��ϵrela="; 
	rela.myPrint(); 
	
	Relation_ship con;
	cout<<"������ϵ����:";
	string ss[100]={"@","23","324"};//������ϵ���� 
	con.get_Con(ss); 
	con.print_Con();
	
	cout<<"rela�����ϵ";
	(rela.get_inverse()).myPrint(); //���ϵ���� 
	cout<<"rela��dom:"<<rela.dom()<<endl;//������ 
	cout<<"rela��ran"<<rela.ran()<<endl;//ֵ�� 
	cout<<"rela��fld"<<rela.fld()<<endl;//�� 
	cout<<"ȫ���ϵ";
	rela.get_all_A_B(re1,re1);
	rela.myPrint();
	cout<<"��ȹ�ϵ";
	rela.get_Ia(re1);
	rela.myPrint();
	cout<<"���ڹ�ϵ";
	rela.get_Bigger(re1);
	rela.myPrint();
	cout<<"С�ڹ�ϵ";
	rela.get_Smaller(re1);
	rela.myPrint();
	cout<<"������ϵ"; 
	rela.get_divide(re1);
	rela.myPrint();
	
}
void test_operator()
{
	
	cout<<endl<<"���ּ������ϵ֮��Ĳ���"<<endl; 
	Relation_ship rela;
	rela.setFirst_Second(re1,re3); //���ɹ�ϵ{<1,3>,<2,4>,<3,5>} 
	cout<<"rela:";
	rela.myPrint();
	mySet set(s4),set2(s5);//����set{2,3} 
	cout<<"set:";
	set.myPrint();
	cout<<"set2:";
	set2.myPrint();
	cout<<"set��rela������="<<limit(rela,set)<<endl; //���ƵĲ���
	
	cout<<"set��rela�ϵ���"<<mirror(rela,set)<<endl;//��Ĳ��� 

    cout<<"����rela�Ƿ�Ϊset�ϵĶ�Ԫ��ϵ";
	if(isA_Relation(rela,set))cout<<"yes"<<endl;//����rela�Ƿ�Ϊset�ϵĶ�Ԫ��ϵ
	else cout<<"no"<<endl;
	cout<<"����rela�Ƿ�Ϊset2�ϵĶ�Ԫ��ϵ";
	if(isA_Relation(rela,set2))cout<<"yes"<<endl;
	else cout<<"no"<<endl;
	
	Relation_ship R;
	cout<<"set��С�ڹ�ϵ����"<<set_smaller_re(R,set)<<endl;//set��С�ڹ�ϵ����
	cout<<"set�ĺ�ȹ�ϵ����"<<set_equal_re(R,set)<<endl; //set�ĺ�ȹ�ϵ���� 
}
void test_overload()
{
	cout<<endl;
	cout<<"overload:"<<endl;
	mySet set1(s6),set2(s7);
	cout<<"set1+set2="<<toSetString(set1+set2)<<endl;
	cout<<"set1-set2="<<toSetString(set1-set2)<<endl;
	
	Relation_ship R,R1(re1);
	cout<<"exception handling:";
	R1=R;
}
