// test.cpp : 定义控制台应用程序的入口点。
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
	get_data();//读取信息 
	test_set();
	test_relation();
	test_operator();
	test_overload();
	getchar(); 
	return 0;
}

