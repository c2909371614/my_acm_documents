#include<bits/stdc++.h>
using namespace std;
//处理后缀表达式
int Degree(char c) {
	if (c == '(')
		return 5;
	else if (c == '^')
		return 4;
	else if (c == '*'||c =='/'||c == '%')
		return 3;
	else if (c == '+')
		return 2;   // 相当于q^p
	else if (c == '-'||c == '+')
		return 2;   // 相当于qVp，优先级最低
	else
		return 0;
}
double Num_case[26];//用于运算数的储存
void Turn_to_letter(string &s) { //将运算数转化成字母
	memset(Num_case,0,sizeof(Num_case));//初始化为0
	string ans;//作为答案过渡
	char temp_letter='a';
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			Num_case[temp_letter-'a']=Num_case[temp_letter-'a']*10+s[i]-'0';//字符转数字 ，前面的数位权++
		} else {
			if(s[i-1]>='0'&&s[i-1]<='9') {
				
				ans+=temp_letter;
				temp_letter++;
			}
			ans+=s[i];

		}
	}
	s=ans;
}
string MidToPost(string &c) {    //求表达式对应的后缀表达式
	stack<char> s;           //字符串中去手动去空格
	string q="";
	int n = c.size() ;
	for (int i = 0; i<n; i++) {
		if (c[i] != ' ') {   // 除去空格
			// 如果遇到运算数，直接加入到队列中，用队列来放后缀表达式
			if (c[i] >='a'&&c[i]<='z') {
				q += c[i];
			} else if (!s.size()) {
				s.push(c[i]);// 如果栈为空，遇到运算符直接入栈
			} else if (c[i] == ')') {
				// 如果是右括号，则弹出对应左括号前的所有的运算符 ，加入到队列中
				while (s.top() != '(') {
					q += s.top();
					s.pop();
				}
				s.pop();      // 弹出左括号
				continue;//
			} else if (Degree(s.top()) == 5 || (Degree(c[i]) > Degree(s.top()))) {
				s.push(c[i]);  // 如果栈顶是左括号，或者当前优先级高，都入栈
			} else if (Degree(s.top()) != 5 && Degree(c[i]) <= Degree(s.top())) {
				q += s.top();
				s.pop();              // 如果遇到运算符没有栈顶运算符级别高，出栈
				while (!s.empty() && Degree(s.top()) != 6 && Degree(c[i]) <= Degree(s.top())) {
					q+=s.top();  // 从栈中弹出比当前优先级高的运算符
					s.pop();
				}
				s.push(c[i]);  //将当前运算符加入到队列
			}
		}
	}
	while (!s.empty()) {
		q += s.top();      // 最后将栈里面所有元素弹出加入到队列
		s.pop();
	}
	c=q;
	return q;
}

//此部分用于运算后缀表达式
int GetValuePost(string q) {
	double ans=Num_case[0];//答案
	for(int i=0; i<q.size(); i++) {
		switch(q[i]) {
			case '+':
				ans+=Num_case[q[i-1]-'a'];
				break;
			case '-':
				ans-=Num_case[q[i-1]-'a'];
				break;
			case '*':
				ans*=Num_case[q[i-1]-'a'];
				break;
			case '/':
				ans/=Num_case[q[i-1]-'a'];
				break;
			case '^':
				ans=pow(ans,Num_case[q[i-1]-'a']);
				break;
		}
	}
	return ans;
}

void print()
{
	for(int i=0;i<26;i++)
		cout<<Num_case[i]<<endl;
}
int main() {
	string s;
	try {
		cin>>s;
		if(s[s.size()-1]!='=')
			throw 1;
		Turn_to_letter(s);
		cout<<s<<endl;
		cout<<MidToPost(s)<<endl;
		cout<<GetValuePost(s)<<endl;
		print();
	}
	catch(int)
	{
		cout<<"please enter '=' "<<endl;
	}

}
