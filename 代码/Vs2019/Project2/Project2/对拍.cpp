#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<iostream>
#include<fstream>
#include<iomanip>
#include <process.h>
using namespace std;
int run_time = 100;//���д��� 
int main()
{	system("comp");
	for(int i = 1; i <= run_time; i++){
		//·��
		system("comp");
		system("����ַ�.exe");
		double now_t = clock();//��ǰcup����ʱ��
		system("11-D_test.exe");
		double end_t = clock();//�ҵ�ʱ��
		system("11_D_AC_code.exe");
		char command[100] = "comp AC_data.out my_data.out";
		if(system(command))
		{
			cout << "Wrong ans" << endl;
			return 0;
		 } 
		else 
			cout <<"Accepted,���Ե�#" << i <<",��ʱ" << setprecision(2)<<end_t - now_t << "ms" <<endl;
	} 
}
