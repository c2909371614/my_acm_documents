#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<string>
using namespace std;
class Guest {
	public:
		Guest() {
		}
		Guest(string newName,double newMeter,double newSalary, double newHandsome) {
			name=newName;
			meter=newMeter;
			salary=newSalary;
			handsome=newHandsome;
		}
		double getMeter() {
			return meter;
		}
		double getSalary() {
			return salary;
		}
		double getHandsome() {
			return handsome;
		}
		string getName() {
			return name;
		}
		bool setOffer(bool newOffer) {
			offer=newOffer;
		}
		bool getOffer() {
			return offer;
		}
	private:
		string name;
		double meter,salary,handsome;//meter is high(m);salary(k yuan);handsome(1-30)
		bool offer;
};
int research(Guest p,Guest pA) { //select satisfied girls ,meet requirement return 1,else
	//returrn 0
	if(p.getMeter()<pA.getMeter())return 0;
	if(p.getSalary()<pA.getSalary())return 0;
	if(p.getHandsome()<pA.getHandsome())return 0;//
	return 1;//puts("*");
}
int main() {
	Guest girls[3]= {Guest("A",1.55,10,20),Guest("B",1.7,5,12),Guest("C",1.6,100,25)}; //储存数据（人选）
	int choose, i;;
	cout<<"please girl guests choose join or not(1 is yes,0 is no )"<<endl;

	for(i=0; i<3; i++) {
		cout<<i+1<<"th guest:";
		cin>>choose;
		if(choose==1) girls[i].setOffer(true);//choose yes or no
		else girls[i].setOffer(false);
	}
	puts("high unit is meter(m);salary unit is (k yuan);chraming(1-30)");
	puts("enter your require(high salary index):");//tell input
	//scanf("%lf%lf%lf",&pA.getMeter,&pA.CNY,&pA.Index);
	double pAgetMeter,pAgetSalary,pAgetHandsome;
	cin>>pAgetMeter>>pAgetSalary>>pAgetHandsome;
	Guest pA("require",pAgetMeter,pAgetSalary,pAgetHandsome);//constrcutor input
	bool flag=true;
	for(i=0; i<3; i++) { //call research function to select
		if(research(girls[i],pA)==1&&girls[i].getOffer()) {
			if(flag) {
				puts("satisfied girls") ;
				puts("name\thigh\tsalary\tIndex");//print form
				flag=false;
			}
			cout<<girls[i].getName();
			printf("\t%.2f\t%.2f\t%.0f\n",girls[i].getMeter(),girls[i].getSalary(),girls[i].getHandsome());
		}
	}
	return 0;
}
