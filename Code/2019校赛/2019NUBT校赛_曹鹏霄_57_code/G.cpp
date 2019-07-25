#include<bits/stdc++.h>
#define ll long long
const int MAX=1e5+5;
using namespace std;
struct star{
	char sex;
	string num;
	string name;
	int score;
};
bool cmp(star A,star B)
{
	return A.score<B.score;
}
int main()
{
	int T;
	cin>>T;
	star a[MAX];
	vector <star>men,women;
	int n;
	while(T--){
		men.clear();
		women.clear();
		
		cin>>n;
		for(ll i=0;i<n;i++){
			cin>>a[i].name>>a[i].sex>>a[i].num>>a[i].score;
			if(a[i].sex=='M')men.push_back(a[i]);
			else  women.push_back(a[i]);
		} 
		sort(men.begin(),men.end(),cmp);
		sort(women.begin(),women.end(),cmp);
		if(!women.empty())
			cout<<women[women.size()-1].name<<" "<<women[women.size()-1].num<<endl;
		else cout<<"Miss"<<endl;
		if(!men.empty())
			cout<<men[0].name<<" "<<men[0].num<<endl;
		else cout<<"Miss"<<endl;
		if(!men.empty()&&!women.empty())
			cout<<women[women.size()-1].score-men[0].score<<endl;
		else cout<<"Null"<<endl;
	}
	men.clear();
	women.clear();
}
