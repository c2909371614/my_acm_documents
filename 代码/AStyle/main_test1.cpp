#include <bits/stdc++.h>
#include<string>
using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int myReplace(string & s1,const string s2,const string s3) { //把s1中粗线的第一个s2用s3替换
	s1.replace(s1.find(s2),s2.size(),s3);
	return 0;
}
int main(int argc, char** argv) {
	string s="helloworld";
	int count=0;
	int pos=0;
	while(s.find('l',pos)!=string::npos) {
		pos=s.find('l',pos)+1;
		count++;
		cout<<pos<<endl;
	}

	cout<<count<<endl;
}
