#include<bits/stdc++.h>
using namespace std;
int myReplace(string &s,const string& s1,const string& s2);

int main() {
fstream io("例8.2.txt",ios:in|ios::app);
	string s,s_num,s_alp;//A用数字表示B用字母表示
	io>>s;
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9')
			s_num+=s[i];
		else if(s[i]>='a'&&s[i]<='z')
			s_alp+=s[i];
	}
	string ss,f("{}");
	for(int i=0; i<pow(s_alp.size(),s_num.size()); i++) {
		for(int j=0; i<s_num.size(); i++) {
			streamstring temp;
			temp<<"<"<<
				f.insert(1,"")
		}

	}
}
int myReplace(string &s,const string& s1,const string& s2 ) { //用s2替换s中第一个出现的s1
	s.replace(s.find(s1),s1.size(),s2);
	return s.size();
}
