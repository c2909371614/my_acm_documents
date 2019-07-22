#include<iostream>
#include<cstring>
#include<cstdlib>
#include<cstdio>
using namespace std;
int main()
{
	char a[100],b[10];
	FILE* sq=NULL;
	puts("enter the root");
	gets(a);
	puts("enter open way");
	gets(b);
	if((sq=fopen(a,b))==NULL){
		cout<<"open file fail"<<endl;
		exit(0);
	}
	char s[100];
	fprintf(sq,"102 sad");
	fprintf(sq,"102 sad");
	
//	puts("enter your information");
//	gets(s);
	exit(0);
}
