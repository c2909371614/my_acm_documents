#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<sstream>//stringstream
using namespace std;
class C {
	public:
		C();
		C(const C&c);
		~C();
		C(int,int);
		C operator+(const C &c);
		int getN();
		int getD();
		string toString()const;

	private:
		int n;//numerator
		int d; //denominator
};
int main() {
	C c1(1,2),c2(2,3);
	cout<<c1.getN()<<endl;
}
C::C() {
	n=1;
	d=1;
}
C::C(const C & c) {
	n=c.n;
	d=c.d;
}
C::~C() {
	cout<<"done"<<endl;
}
C::C(int newN,int newD) {
	n=newN;
	d=newD;
}
C::C operator+(const C & c) {
	int t_newD=c.getD()*d;
	int t_newN=(n*c.getD()+c.getN()*d);
	int factor=Gcd(t_newD,t_newD);
	int newN=t_newN/factor,newD=t_newD/factor;
	return C(t_newN,t_newD);
}
string C::toString()const {
	stringstream  ss;
	ss<<n;
	if(d>1)
		ss<<"/"<<d;
	return ss.str();
}
int C::getN() {
	return n;
}
int C::getD() {
	return d;
}
