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
	 
	//srand(time(0)); 
	int high = rand()%1000 + 1;//º¯Êý 
	for(int j = 0; j < high; j++)
	{
		data.clear(); 
		int len = rand()%20 + 1;//×Ö·û³¤¶È
		for(int i = 0; i < len; i++)
			data+=Random_char();
		ss[j] = data;
		//out << data.c_str() << endl;
	}
	sort(ss, ss+high,cmp);
	for(int j = 0; j < high; j++)
		out << ss[j].c_str() << endl;
	out.close();
}
