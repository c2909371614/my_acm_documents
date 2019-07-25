#include <bits/stdc++.h>
using namespace std;
const int SIZE = 50000+10;
int a[SIZE],n,m;
char op;
int l,r;
struct tree {
	int l,r,max;
} t[SIZE*4];

void build(int p,int l,int r) {
	t[p].l=l;
	t[p].r=r;
	if(l==r) {
		t[p].max=a[l];
		return;
	}
	int mid=(l+r)/2;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p].max=max(t[p*2].max,t[p*2+1].max);
}

void change(int p,int x,int d) {
	if(t[p].l==t[p].r) {
		t[p].max=d;
		return;
	}
	int mid=(t[p].l+t[p].r)/2;
	if(x<=mid) change(p*2,x,d);
	else change(p*2+1,x,d);
	t[p].max=max(t[p*2].max,t[p*2+1].max);
}

int ask(int p,int l,int r) {
	//printf("%d:L-R:%d-%d\n", p, t[p].l, t[p].r);
	if(l<=t[p].l&&r>=t[p].r) {
		return t[p].max;
	}//	cout<<"FFSD"<<endl;
	int mid = (t[p].l+t[p].r)/2;
	int val = -(1<<30);
//	cout << val;
	if(l<=mid) val = max(val,ask(p*2,l,r));
	if(r>mid) val = max(val,ask(p*2+1,l,r));
	return val;
}

int main() {
	while(~scanf("%d%d",&n,&m)) {
		//
		for(int i=1; i<=n; i++) {
			scanf("%d", &a[i]);
		}
		build(1,1,n);
		getchar();
		while(m--) {
			scanf("%c",&op);
			if(op=='Q') {
				scanf("%d%d",&l,&r);
				//	cout<<"***"<<endl;
				printf("%d\n",ask(1,l,r));
			} else if(op=='U') {
				scanf("%d%d",&l,&r);
				change(1,l,r);
			}
			getchar();
		}
	}
}

