#include<iostream>
using namespace std;
class P {
	public:
		P() {
			cout<<"invoked"<<endl;
		}
};
class C:public P {
	public:
		C(int a) {
			cout<<"1"<<endl;
		}
};
int main() {
	C c(1);

}
