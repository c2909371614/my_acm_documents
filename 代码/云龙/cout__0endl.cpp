#include <bits/stdc++.h>
using namespace std;
class Complex {
	public:
		Complex(double newa,double newb) {
			a=newa;
			b=newb;
		}
			~Complex() {
			a=0.0;
			b=0.0;
		}
		double show() {
			//cout << a << " + " << b << "i"<<endl;
			return (double)0;
		}
		Complex(Complex& c) {
			a = c.a;
			b = c.b;
		}
		
		double add(Complex c) {
			a=c.a+a;
			b=c.b+b;
			cout << a << " + " << b << "i"<<endl;
		}
	private:
		double a,b;
};
int main() {
	Complex c1(3,5);
	Complex c2 (4.5,0);
	Complex c3 (c1);
	cout<<c1.show()<<endl;
	cout<<c2.show()<<endl;
	cout<<c3.show()<<endl;
	cout<<endl; 
	cout<<c1.add(c2)<<endl;
	return 0;
}

