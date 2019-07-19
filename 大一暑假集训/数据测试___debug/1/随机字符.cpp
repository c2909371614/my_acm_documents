#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 4;
const int N = 2e5;
const int M = 5e3-1;
int Random(int n)//产生1-n的随机数，没有0包括n 
{
	//srand(time(0));
	return rand()*rand() % n + 1;
}
char Random_char()
{
	//srand(time(0));
	return rand()%26 + 'a';
}
int main()
{
	string data;
	string ss[MAX];
	fstream out("data.in",ios::out);
	srand(time(0)); 
	 
	//srand(time(0)); 
	int n = Random(100)+1, m = Random(100);
	out << n << " " << m << endl;//n m
	char ch[2]= {'Q', 'U'};// 
	for(int j = 0; j < n; j++){
		out << Random(100) ;
		if(j != n - 1)out << " ";
	}
		
	out << endl; 
	for(int j = 0; j < m; j++)
	{
		int x = rand()%2;
		if(ch[x] == 'U')out << ch[x] << " " << Random(n) << " " << Random(100) << endl;
		else {
			int a = Random(n), b = a + Random(n-a);
			out << ch[x] << " " << a << " " << b << endl;
		}
	}
	out.close();
}
