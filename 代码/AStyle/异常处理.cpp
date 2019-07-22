#include<bits/stdc++.h>
#include<stdexcept>
using namespace std;
class Rangle {
	private:
		double a,b,c;
	public:
//		Rangle(){
//
//		}
		void input() {
			cout<<"enter three numbers:";
			cin>>a>>b>>c;
			try {
				if(a>=b+c||a<=abs(b-c))
					//throw a;
					throw runtime_error("error: your input a b c can't make up a Trirangle because a>=b+c or a<=abs(b-c)");
				cout<<"accepted and three side lenth:"<<a<<" "<<b<<" "<<c<<endl;
			}
			//catch(double ex)
			catch(runtime_error& ex) {
				cout<<ex.what()<<endl;
				//cout<<"error: your input a b c can't make up a Trirangle because a>=b+c or a<=abs(b-c)"<<endl;
			}

		}
};
int main() {
	Rangle a;
	while(true) {
		a.input();

	}


}

