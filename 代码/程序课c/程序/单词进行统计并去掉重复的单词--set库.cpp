#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;
set<string> dict;//创建set库 
 
int main()
{
	string s,buf;
	while(cin>>s && s !="#")  
	{
		for(int i=0;i<s.length();i++)
		{
			if(isalpha(s[i]))//判断是否为单词 
			    s[i]=tolower(s[i]);//统一为小写 
			else
			    s[i]=' '; 
		} 
		stringstream ss(s);//将字符串s放入流中 
		while(ss>>buf)//将流中的单词导出到buf临时存放 
		dict.insert(buf);/*用stringstream的形式将单词导入set中，这个可以排除空格或者符号的干扰 */
	}
	for(set<string>::iterator it=dict.begin();it!=dict.end();it++)/*使用迭代器输出set中的单词 */
	    cout<<*it<<endl;
}

