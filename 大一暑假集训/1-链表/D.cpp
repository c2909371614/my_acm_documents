#include<bits/stdc++.h>
#define ll long long
#define FAST_IO std::ios::sync_with_stdio(false);
using namespace std;

const int MAX = 1e5 + 5;
struct Node {
	int val;
	int index;
	Node(int x = -1,int y = -1):val(x),index(y) {}
	bool operator<(const Node &x) const {
		return index < x.index;
	}
};
//bool operator<(const Node &a, const Node &b)
//{
//	return a.index < b.index;
//}
list<Node> A,  B;
int n;
int main() {
	FAST_IO;
	cin >> n;
	int N = 0;//´ÎÐò
	while(n) {
		A.clear();
		B.clear();
		int cnt = 0;
		string type;
		char genth;
		int x;
		cout << "Case #" << ++N << ":" << endl;
		while(n--) {
//			cout << "ojasd" << endl;
//			getchar();
			cin >> type >> genth;
//			cout << "ojasd" << endl;
			if(type == "push") {
				cin >> x;
				//		cout<<"cin>>x"<<endl;
				if(genth == 'A')A.push_back(Node(x, cnt++));
				else B.push_back(Node(x, cnt++));
				//		genth == 'A'?cout<<A.back().val<<endl:cout<<B.back().val<<endl;
			} else if(type == "pop") {
				if(genth == 'A')
					cout << A.back().val << endl,
					     A.pop_back();
				else
					cout << B.back().val <<endl,
					     B.pop_back();
			} else if(type == "merge") {
				char y;
				cin >> y;
				if(genth == 'A') {
					A.merge(B);
					B.clear();
				}

				else {
					B.merge(A);
					A.clear();
				}
			}
		}
		cin >> n;
	}
}


