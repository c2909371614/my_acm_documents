#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include <process.h>
using namespace std;
int run_time = 10000;//运行次数 
string rand_exe = "Rand_char.exe";
string test_exe = "M.exe";
string AC_exe = "mm.exe";
string AC_out = "1.out";
string my_out = "2.out"; 
int main()
{	//system("comp");
	for(int i = 1; i <= run_time; i++){
		//路径
		//system("comp");
		system(rand_exe.c_str());
		double now_t = clock();//当前cup运行时间
		system(test_exe.c_str());//运行我的程序 
		double end_t = clock();//我的时间
		system(AC_exe.c_str());//运行AC的程序 
		//system("pause");
		string command;
		command = (string)"fc "+ AC_out + (string)" " + my_out;//调用fc命令 
		if(system(command.c_str()))
		{
			cout << "Wrong ans" << endl;
			return 0;
		 } 
		else 
			cout <<"Accepted,测试点#" << i <<",用时" << setprecision(2)<<end_t - now_t << "ms" <<endl;
	} 
	
}
