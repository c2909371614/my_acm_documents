#ifndef MAINHEAD
#define MAINHEAD
#include<string>
#include<cstring>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<sstream>
#include<fstream>
using namespace std;
class Relation_ship;//��ǰ����Relation_ship��һ��class 
class mySet {
	private:
		char name;//Set name no define
		string element;//����Ԫ���ַ�
		vector<int> ele;
		string pick_ele(const string &s);//��ȡԪ�� 
	
	friend string limit(Relation_ship &R,mySet &A); //��ϵ�뼯��֮������� 1.A��R������ 
	friend string mirror(const Relation_ship &R,const mySet &A);//2.A��R�µ��� 
	friend bool isA_Relation(Relation_ship &R,mySet &A);//R�Ƿ�ΪA�ϵĶ�Ԫ��ϵ �޷��ж�������ϵ 
	friend string set_smaller_re(Relation_ship &R,mySet &A);//����set�ϵ�С�ڹ�ϵRelation_ship
	friend string set_equal_re(Relation_ship &R,mySet &A);//����set�ϵĺ�ȹ�ϵ 
	public:
		mySet();
		mySet(const string s); //s={a,b,c}
		mySet(const int a[],int n);//Initialize object by Array  n is lenth of array
		mySet(mySet &set);
		mySet operator=(mySet &set);
		~mySet();
		string getEle()const;
		void setEle(const string s);//�����Ż��ߴ�Ԫ�ؽ���initalize 
		void myPrint();
		//����Ϊinline 
		int myFind_ele(const string &s);//1 return the first element index of s
		int getEleNum();//2
		string getSet();//3 return set ��ʽstring 
		bool Belong();//4 ����һ�����ж��Ƿ�����set		
		string sumSet(mySet set);//5 �ϼ�
		string operator+(mySet set);
		string subSet(mySet set);//6 subSet�Ӽ� 
		bool isEmpty();//7 
		string DiffSet(mySet set);//8 �
		string operator-(mySet set);
		int subNum();//9 �Ӽ�����
		bool isSubSet(mySet set); //10 �Ƿ�ΪmySet���Ӽ�
		bool isRealSub(mySet set);//11 �Ƿ�ΪmySet�����Ӽ�
		string oppsDiffSet(mySet set);//12 �ԳƲ
		bool isEqual(mySet set); //13 �ж��Ƿ����
};
string toSetString(string ele);
string noSame(string s);
const int max_len=205;//lenth 

#endif
