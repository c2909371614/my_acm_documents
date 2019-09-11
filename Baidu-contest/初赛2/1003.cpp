#include<bits/stdc++.h>
using namespace std;
//�����׺���ʽ
int Degree(char c) {
	if (c == '+') return 6;
	if (c == '^') return 1;
	return 0;
}
string MidToPost(string c) {    //����ʽ��Ӧ�ĺ�׺���ʽ
	stack<char> s;           //�ַ�����ȥ�ֶ�ȥ�ո�
	string q="";
	int n = c.size() ;
	for (int i = 0; i<n; i++) {
		if (c[i] != ' ') {   // ��ȥ�ո�
			// ���������������ֱ�Ӽ��뵽�����У��ö������ź�׺���ʽ
			if (c[i] == '1') {
				q += c[i];
			} else if (!s.size())
				s.push(c[i]);// ���ջΪ�գ����������ֱ����ջ
			else if (Degree(s.top()) == 6 || (Degree(c[i]) > Degree(s.top()))) {
				s.push(c[i]);  // ���ջ���������ţ����ߵ�ǰ���ȼ��ߣ�����ջ
			} else if (Degree(s.top()) != 6 && Degree(c[i]) <= Degree(s.top())) {
				q += s.top();
				s.pop();              // ������������û��ջ�����������ߣ���ջ
				while (!s.empty() && Degree(s.top()) != 6 && Degree(c[i]) <= Degree(s.top())) {
					q+=s.top();  // ��ջ�е����ȵ�ǰ���ȼ��ߵ������
					s.pop();
				}
				s.push(c[i]);  //����ǰ��������뵽ջ
			}
		}
	}
	while (!s.empty()) {
		q += s.top();      // ���ջ��������Ԫ�ص������뵽����
		s.pop();
	}
//	cout << q << endl;
	return q;
}

//�˲������������׺���ʽ
char GetValuePost(string q) {
	//��׺���ʽ��ֵ
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
					break;//'q^p'����Ϊq&&p
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
			while(ntemp) { //��ȡ������
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

