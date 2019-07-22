#include <iostream>
using namespace std;
bool prime(int a)
{
    if(a<=1) return 0;
    for(int i=2;i*i<=a;i++)
    {
        if(a%i==0)
            return 0;
    }
    return 1;
}

int main()
{
	int x,y;
	while(cin>>x>>y){
		if(x==0&&y==0) break;
		bool flag=true;
		for(int i=x;i<=y;i++){
			if(!prime(i*i+i+41)){
				flag=false;
				break;
			}
		}
		if(flag) cout<<"OK"<<endl;
		else cout<<"Sorry"<<endl;
	}
	return 0;
}
