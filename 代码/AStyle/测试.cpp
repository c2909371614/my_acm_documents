#include<bits/stdc++.h>
using namespace std;
class C {
	private:
		static int a;
		int b;
	public:
		int getA() {
			return a;
		}
		int setA(int a) {
			this->a =a;
		}
		int getB() {
			return b;
		}
};
int C::a=2;
//int C::b=1;
int main() {
	C c1,c2;
	c1.setA(5);
	cout<<c1.getA() <<" "<<c2.getA()
		<<endl;
}

