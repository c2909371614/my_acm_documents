#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
using namespace std;
class C {
	public:
		C(int new_n,int new_d) {
			n=new_n;
			d=new_d;
		}
		C operator+(const C& c) {
			int factor=gcd(c.getD,d);
			int newD=c.getD*d/factor;
			int newN=(n*c.getD+c.getN*d)/factor;
			return C(newN,newD);
		}
//		C add(C c){
//			int factor=gcd(c.getD,d);
//			int newD=c.getD*d;
//			int newN=n*c.getD+c.getN*d;
//			return C(newN,newD);
//		}
		int gcd(int a,int b) {
			if(b==0)return a;
			else return gcd(b,a%b);
		}
		int getN() {
			return n;
		}
		int getD() {
			return d;
		}
		string toString()const {
			stringstream  ss;
			ss<<n;
			if(d>1)
				ss<<"/"<<denominator;
			return ss.str();
		}
	private:
		int  n,d;


		int gcd(int a,int b) {

			if(b==0)return a;
			else return gcd(b,a%b);
		}
		int main() {
			C c1(1,2),c2(2,3);
			//C c3=c1.add(c2);
			cout<<c3.getN()<<"/"<<c3.getD()<<endl;
			C c1,c2;
			cout<<(c1+c2).n<<"/"<<(c1+c2).d<<endl;
		}
//class C {
//	public:
//		int n=1,d=2;
//		C operator+(const C& c) {
//			C c1;
//			c1.n=n+c.n;
//			c1.d=d+c.d;
//			return c1;
//			}
//		};
//int main() {
//	C c1,c2;
//	cout<<(c1+c2).n<<"/"<<(c1+c2).d<<endl;
//}
