#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void quick_ran_name() {
	fstream io("ran_name.txt",ios::in);//打开文件用于读取 
	int num;//个数 
	vector<string>vec_name/*读取文件里的data*/,temp_vec_name;//中间过度量;
	string name;
	while(io>>name)
	{
		vec_name.push_back(name);
	}
	time_t Time1,Time2;//time_t是一个特殊的结构体用于时间的储存
	do {
		temp_vec_name.clear();//中间过度量 
		for(int i=0; i<vec_name.size(); i++)
			temp_vec_name.push_back(vec_name[i]);
		cout<<"输入你要的个数,输入0程序结束"<<endl;
		cin>>num;
		try{
			if(num>temp_vec_name.size())
				throw num;
		
		for(int i=0; i<num; i++) {
			srand(time(0));
			int ch=rand()%temp_vec_name.size();
			temp_vec_name.erase(temp_vec_name.begin()+ch,temp_vec_name.begin()+ch+1);//删除已选的
			cout<<temp_vec_name[ch]<<" ";
			Sleep(100);
		}
		cout<<endl;
		}
		catch(int num)
		{
			cout<<num<<" is bigger than the number of the data"<<endl;
		}
	} while(num!=0);
	io.close();//关闭文件 
}
int main()
{
	quick_ran_name(); 
 } 

