//stackµÄÊµÏÖpop() push() front() empty();
#include<iostream>
using namespace std;
struct stack {
	int a[10000],i=0;
	void push(int x) {
		a[++i]=x;//cout<<"a[i]"<<a[i]<<' ';
	}
	int front() {
		return a[i];
	}
	void pop() {
		i--;
		//printf("%d ",a[i]);
	}
	int empty() {
		return i>0? 1:0;
	}
};
int main() {
	struct stack st;
	int b[100],i=0,count=0;
	while(cin>>b[++i]) {
		if(b[i]==-1)break;
		st.push(b[i]);
		cout<<st.front()<<endl;
		count++;
	}
	while(count--) {
		st.pop();
		printf("empty=%d ",st.empty());
	}
}
