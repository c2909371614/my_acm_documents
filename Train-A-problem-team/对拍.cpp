#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include <process.h>
using namespace std;
int run_time = 10000;//���д��� 
string rand_exe = "Rand_char.exe";
string test_exe = "M.exe";
string AC_exe = "mm.exe";
string AC_out = "1.out";
string my_out = "2.out"; 
int main()
{	//system("comp");
	for(int i = 1; i <= run_time; i++){
		//·��
		//system("comp");
		system(rand_exe.c_str());
		double now_t = clock();//��ǰcup����ʱ��
		system(test_exe.c_str());//�����ҵĳ��� 
		double end_t = clock();//�ҵ�ʱ��
		system(AC_exe.c_str());//����AC�ĳ��� 
		//system("pause");
		string command;
		command = (string)"fc "+ AC_out + (string)" " + my_out;//����fc���� 
		if(system(command.c_str()))
		{
			cout << "Wrong ans" << endl;
			return 0;
		 } 
		else 
			cout <<"Accepted,���Ե�#" << i <<",��ʱ" << setprecision(2)<<end_t - now_t << "ms" <<endl;
	} 
	
}
