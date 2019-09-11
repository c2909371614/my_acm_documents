#include <bits/stdc++.h>
using namespace std;
string n,m;
class Read_data {
	public:
		Read_data() {
			freopen("data.in","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
			freopen("1.out","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
		}
		~Read_data(){
			fclose(stdin);//关闭文件
			fclose(stdout);//关闭文件
		} 
}READ;
int main()
{
	int x,y,y1,y2,s1=0,s2=0,ss=0;
	cin>>x>>y;
	cin>>n>>m;
	y1=y;
	y2=y;
	if(x>y){
		for(int i=0;i<x;i++)
		{
			if(n[i]==m[y-y1] && y1>0)
			{
				if(n[i]==m[y-y1]) ss++;
				y1--;
				s1++;
			}
			else if(y1==0 || n[i]>m[y-y1])
			{
				s1=s1+x-i;
				y1=0;
				ss=0;
				break;
			}	
		}
		for(int i=0;i<x;i++)
		{
			if(n[i]>m[0])
			{
				s2=x-i;
				y2=0;
				break;
			}
		}
	}
	else if(x==y){
		for(int i=0;i<x;i++)
		{
			if(n[i]==m[y-y1] && y1>0)
			{
				if(n[i]==m[y-y1]) ss++;
				y1--;
				s1++;
			}
			else if(y1==0 || n[i]>m[y-y1])
			{
				s1=s1+x-i;
				y1=0;
				ss=0;
				break;
			}	
		}
		for(int i=0;i<x;i++)
		{
			if(n[i]>m[0])
			{
				s2=x-i;
				y2=0;
				break;
			}
		}
	}
	else{
		for(int i=0;i<x;i++)
		{
			if(n[i]==m[y-y1] && y1>0)
			{
				if(n[i]==m[y-y1]) ss++;
				y1--;
				s1++;
			}
			else if(y1==0 || n[i]>m[y-y1])
			{
				s1=s1+x-i;
				y1=0;
				ss=0;
				break;
			}	
		}
		for(int i=0;i<x;i++)
		{
			if(n[i]>m[0])
			{
				s2=x-i;
				y2=0;
				break;
			}
		}
	}
	if(ss==y) cout<<"-1"<<endl;
	else if(y1==0 || y2==0) cout<<max(s1,s2)<<endl;
	else cout<<"-1"<<endl;
}

