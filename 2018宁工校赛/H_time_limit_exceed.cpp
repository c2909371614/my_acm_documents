#include<bits/stdc++.h>
using namespace std;
const int MAX=1e5+5;
int main() {
    int T;
    int a[MAX];
    cin>>T;
    while(T--) {
        int n;
        cin>>n;
 
        for(int i=0; i<n; i++)
            cin>>a[i];
 
        int max=2,min=2;
        bool flag;//记录是否存在结果
        for(int i=n-1; i>0; i--) {
            flag=false;//记录是否存在结果每次都要记录并初始化 
            for(int j=0; j<a[i]; j++) {
                if((min+j)%a[i-1]==0) {
                    min=min+j;//cout<<"ok"<<endl;
                    flag=true;
                    break;
                }
            }
            if(flag==false) {
                cout<<-1<<endl;
                break;
            }
 
            for(int j=a[i]-1; j>=0; j--) {
                if((max+j)%a[i-1]==0) {
                    max+=j;
                    break;
                }
            }
        //  cout<<"max:"<<max<<" min:"<<min<<endl;
        }
        if(flag)
            cout<<min<<" "<<max+a[0]-1<<endl;
    }
}
