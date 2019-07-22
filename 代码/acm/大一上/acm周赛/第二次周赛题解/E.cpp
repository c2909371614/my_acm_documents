#include <iostream>
#include <algorithm>
using namespace std;
//#define N 105
int main(){
    int t;
    cin>>t;
    string s1,s2,s3;
    while(t--)
    {
        cin>>s1>>s2>>s3;
        int l1=s1.size()-1;
        int l2=s2.size()-1;
        int l3=s3.size()-1;
        string ss="";//储存预输出 
        int num=0;
        while(true)
        {
            int yu,nu;//yu用于数据临时处理 
            if(l1>=0)
            {
                yu=(s1[l1]-'0');//转化为integer 
                if(yu==0)yu=10;
            }
            else yu=10;
            if(l2>=0&&l3>=0)
            {
                nu=(s2[l2]-'0')+(s3[l3]-'0')+num;//nu为和 
                num=nu/yu;//mun为进位 
                ss+=('0'+nu%yu);
                l2--;l3--;l1--;
            }
            else if(l2>=0)
            {
                nu=(s2[l2]-'0')+num;
                num=nu/yu;
                ss+=('0'+nu%yu);
                l2--;l3--;l1--;
            }
            else if(l3>=0)
            {
                nu=(s3[l3]-'0')+num;
                num=nu/yu;
                ss+=('0'+nu%yu);
                l2--;l3--;l1--;
            }
            else if(num>0)
            {
                nu=num;
                num=nu/yu;
                ss+=('0'+nu%yu);
                l2--;l3--;l1--;
            }
            else break;
        }
        int flag=1;
        for(int i=ss.size()-1;i>=0;i--)
        {
            if(ss[i]=='0'&&flag&&i==0)cout<<0;//考虑0+0 
            if(ss[i]=='0'&&flag)continue;//若为前面为零则不输出continue 
            else flag=0;//一旦有不为零的数出现后面就输出 
            cout<<ss[i];
        }
            cout<<endl;
    }
	return 0;
}
