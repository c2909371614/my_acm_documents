#include<bits/stdc++.h>
using namespace std;
class Father {
	public:
		Father() {

		}
		virtual void print() {
			cout<<"Father"<<endl;
		}
};
class Son:public Father {
		Son() {

		}
		void print() {
			cout<<"redefine print"<<endl;
		}
};
void display(const Father*p) {
	(*p).print();
}
int main() {
	Son son;
	display(&son);
}
