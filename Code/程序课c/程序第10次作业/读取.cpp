#include<bits/stdc++.h>
using namespace std;
int main()
{
	char a[2],s[100];
	FILE *fp;
	puts("enter file name to read");
	gets(s);
	if((fp=fopen(s,"rb"))==NULL){
		cout<<"file open fail"<<endl;
		exit(0);
	}
	while((fgets(a,3,fp))!=NULL){
		cout<<a;
	}
	getchar();
}
