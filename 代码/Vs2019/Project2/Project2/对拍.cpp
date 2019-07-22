#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<iostream>
#include<fstream>
#include<iomanip>
#include <process.h>
using namespace std;
int run_time = 100;//运行次数 
int main()
{	system("comp");
	for(int i = 1; i <= run_time; i++){
		//路径
		system("comp");
		system("随机字符.exe");
		double now_t = clock();//当前cup运行时间
		system("11-D_test.exe");
		double end_t = clock();//我的时间
		system("11_D_AC_code.exe");
		char command[100] = "comp AC_data.out my_data.out";
		if(system(command))
		{
			cout << "Wrong ans" << endl;
			return 0;
		 } 
		else 
			cout <<"Accepted,测试点#" << i <<",用时" << setprecision(2)<<end_t - now_t << "ms" <<endl;
	} 
}
