#include<iostream>
#include<string>
using namespace std;
string s;
int main()
{
	int t,k=1;
	cin>>t;
	while(t--)
	{
		cin>>s;
		int n=s.size();
		s+=s;
		int _count=0;
		int start=-1;
		for(int i=0;i<n;++i)
		{
			if(s[i]=='c')
			{
				start=i;
				break;
			}
		}
		cout<<"Case #"<<k++<<": ";
		if(start==-1)
		{
			if(n&1)
				cout<<n/2+1<<endl;
			else
				cout<<n/2<<endl;
		}
		else
		{
			bool flag=true;
			int _c=10;
			for(int i=start;i<n+start;++i)
			{
				//cout<<s[i]<<" "<<_c<<endl;
				if(i==n+start-1)
				{
					if(s[i]=='c')
					{
						flag=false;
						break;	
					}
					_c++;
					if(_c<2)
					{
						flag=false;
						break;
					}
				}
				else if(s[i]=='c')
				{
					if(_c<2)
					{
						flag=false;
						break;
					}
					_c=0;
					_count++;
				}
				else
					_c++;
			}
			if(flag)
				cout<<_count<<endl;
			else
				cout<<-1<<endl;
		}
	}
	return 0;
}

