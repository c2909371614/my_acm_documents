#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
void quick_ran_name() {
	fstream io("ran_name.txt",ios::in);//���ļ����ڶ�ȡ 
	int num;//���� 
	vector<string>vec_name/*��ȡ�ļ����data*/,temp_vec_name;//�м������;
	string name;
	while(io>>name)
	{
		vec_name.push_back(name);
	}
	time_t Time1,Time2;//time_t��һ������Ľṹ������ʱ��Ĵ���
	do {
		temp_vec_name.clear();//�м������ 
		for(int i=0; i<vec_name.size(); i++)
			temp_vec_name.push_back(vec_name[i]);
		cout<<"������Ҫ�ĸ���,����0�������"<<endl;
		cin>>num;
		try{
			if(num>temp_vec_name.size())
				throw num;
		
		for(int i=0; i<num; i++) {
			srand(time(0));
			int ch=rand()%temp_vec_name.size();
			temp_vec_name.erase(temp_vec_name.begin()+ch,temp_vec_name.begin()+ch+1);//ɾ����ѡ��
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
	io.close();//�ر��ļ� 
}
int main()
{
	quick_ran_name(); 
 } 

