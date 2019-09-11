#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 4;
char Random_char()
{
	//srand(time(0));
	return rand()%26 + 'a';
}
bool cmp(const string &a,const string &b)
{
	return a < b;
}
int main()
{
	string data;
	string ss[MAX];
	fstream out("data.in",ios::out);
	srand(time(0)); 
	int m = rand()%20 + 1;
	int n = rand()%20 + 1;
	out << m << " " << n << endl;
	for(int i = 0; i < m; i++)
		out << Random_char();
	out << " ";
	for(int i = 0; i < n; i++)
		out << Random_char();
}
