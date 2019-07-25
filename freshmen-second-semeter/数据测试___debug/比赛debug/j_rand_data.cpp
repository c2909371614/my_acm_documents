#include<bits/stdc++.h>
using namespace std;
const int MAX = 1e9 + 4;
int Random(int n)//Ëæ»úÊı 
{
	//srand(time(0));
	return rand()*rand() % n + 1;
}
int main()
{
	fstream out("data.in",ios::out);
	srand(time(0)); 
	 
	//srand(time(0)); 
	int high = rand()%20 + 1;//º¯Êı
	int m, n, a1, a2;
	out << high << endl; 
	for(int j = 0; j < high; j++)
	{	
		m = Random(MAX);
		n = Random(MAX);
		a1 = Random(50);
		a2 = a1 + Random(50);		out << m << " " << n << " " << a1 << " " << a2 << endl;
	}
//		out << ss[j].c_str() << endl;
	out.close();
}
