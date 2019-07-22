#include<bits/stdc++.h>
#define ll long long
const int MAX=1e5+5;
using namespace std;
class star {
	public:
		int x,y,rap;
	star(){
		
	}
	void intput(){
		cin>>x>>y;
		rap=y-x;
	}
};
bool cmp(star A,star B) {
//	if(A.x<B.x)return true;
//	if(A.x>B.x)return false;
	return A.x<B.x;
}
int main() {
	int T;
	cin>>T;
	star XK[MAX];
	while(T--) {
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
			XK[i].intput();
		sort(XK,XK+n,cmp);
		int ans=XK[0].rap;
		int temp=0;
		for(int i=1;i<n;i++)
		{
			
			//cout<<"y y"<<XK[i].y<<" "<<XK[temp].y<<endl;
			if(XK[i].y>=XK[temp].y){
				ans+=XK[i].y-max(XK[temp].y,XK[i].x);
				
				//cout<<"max:"<<max(XK[temp].y,XK[i].x)<<endl;
				temp=i;
			}
				
		}
		cout<<ans<<endl;
//		for(int i=0;i<n;i++)
//			cout<<XK[i].x<<" "<<XK[i].y<<endl;
	}
}
