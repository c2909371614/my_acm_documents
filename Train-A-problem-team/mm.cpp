#include <bits/stdc++.h>
using namespace std;
string n,m;
class Read_data {
	public:
		Read_data() {
			freopen("data.in","r",stdin); //�����ض����������ݽ���in.txt�ļ��ж�ȡ
			freopen("1.out","w",stdout); //����ض���������ݽ�������out.txt�ļ���
		}
		~Read_data(){
			fclose(stdin);//�ر��ļ�
			fclose(stdout);//�ر��ļ�
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

