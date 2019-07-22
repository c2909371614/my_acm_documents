#include <iostream>
#include <stdio.h>
using namespace std;
void reverse(char*p,int j) {
	char c;
	int i=0;
	while(i<j) {
		c=p[i];
		p[i]=p[j];
		p[j]=c;
		i++;
		j--;
	}
}
int main() {
	char c;
	int i,n;
	char *p=new char;
	c=getchar();
	for(i=0; c!=EOF; ++i) {
		p[i]=c;
		c=getchar();
	}
	n=i-2;
	reverse(p,n);
	for(i=0; i<=n; i++) {
		cout<<p[i]<<endl;
	}
	delete []p;
	return 0;
}
