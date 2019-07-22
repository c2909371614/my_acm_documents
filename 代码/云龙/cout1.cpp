#include<bits/stdc++.h>
using namespace std;
class C{
	public:
		C(double newa,double newb);
		~C();
		C(C& c);
		double add(C c);
		double show();
	private:
		double a,b;	
};
C::C(double newa,double newb){
	a=newa;
	b=newb;
}
C::~C() {
	a=0;
	b=0;
}
C::C(C& c){
	a=c.a;
	b=c.b;
} 	
double C::show(){
	cout << a << " + " << b << "i"<<endl;
			return 0;
} 
int main(){
	C c1(3,5);
	c1.show();
	
}
