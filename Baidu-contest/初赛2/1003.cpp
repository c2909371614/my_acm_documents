#include<bits/stdc++.h>
using namespace std;
//处理后缀表达式
int Degree(char c) {
	if (c == '+') return 6;
	if (c == '^') return 1;
	return 0;
}
string MidToPost(string c) {    //求表达式对应的后缀表达式
	stack<char> s;           //字符串中去手动去空格
	string q="";
	int n = c.size() ;
	for (int i = 0; i<n; i++) {
		if (c[i] != ' ') {   // 除去空格
			// 如果遇到运算数，直接加入到队列中，用队列来放后缀表达式
			if (c[i] == '1') {
				q += c[i];
			} else if (!s.size())
				s.push(c[i]);// 如果栈为空，遇到运算符直接入栈
			else if (Degree(s.top()) == 6 || (Degree(c[i]) > Degree(s.top()))) {
				s.push(c[i]);  // 如果栈顶是左括号，或者当前优先级高，都入栈
			} else if (Degree(s.top()) != 6 && Degree(c[i]) <= Degree(s.top())) {
				q += s.top();
				s.pop();              // 如果遇到运算符没有栈顶运算符级别高，出栈
				while (!s.empty() && Degree(s.top()) != 6 && Degree(c[i]) <= Degree(s.top())) {
					q+=s.top();  // 从栈中弹出比当前优先级高的运算符
					s.pop();
				}
				s.push(c[i]);  //将当前运算符加入到栈
			}
		}
	}
	while (!s.empty()) {
		q += s.top();      // 最后将栈里面所有元素弹出加入到队列
		s.pop();
	}
//	cout << q << endl;
	return q;
}

//此部分用于运算后缀表达式
char GetValuePost(string q) {
	//后缀表达式求值
	int r;
	char x, y, ans;
	stack<char> s;
	int n = q.size();//cout<<n<<endl;
	for (int i = 0; i < n; i++) {
		if (q[i] == '1') {
			s.push(q[i]);
		} else {
			y = s.top();
			s.pop();
			x = s.top();
			s.pop();
			switch(q[i]) {
				case '^':
					r = x-'0' ^ y-'0';
					break;//'q^p'定义为q&&p
				case '+':
					r = x-'0' + y-'0';
					break;//
				default:
					break;
			}
			s.push(r+'0');
		}
	}
	ans = s.top();
	return ans;
}
int main() {
//	cout << GetValuePost(MidToPost("1+1"));
	for(int i = 1; i < 10; i++) {
		int n = 1 << (i - 1);
		int bin[10];
		int j = 0;
		
		while(n--) {
			j = 0;
			string s = "";
			int ntemp = n;
			while(ntemp) { //获取二进制
				bin[j++] = ntemp % 2;
				ntemp /= 2;
			}
			for(int j = 0; j < i; j++)
				cout << bin[j], bin[j]? s += "1+": s += "1^";
			s += '1';
			cout << endl;
			cout << s << endl;
			cout << GetValuePost(MidToPost(s)) << endl;
		}
		cout << endl;
	}
}

