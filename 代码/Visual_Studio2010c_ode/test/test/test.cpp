// test.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include"Relation.h"
#include "stdafx.h"
#include<iostream>
#include<cstdio>
using namespace std;
void get_data();
void test_set();
void test_relation(); 
void test_operator();
void test_overload(); 
int _tmain(int argc, _TCHAR* argv[])
{
	get_data();//��ȡ��Ϣ 
	test_set();
	test_relation();
	test_operator();
	test_overload();
	getchar(); 
	return 0;
}

