#include<bits/stdc++.h>
using namespace std;
//�����׺���ʽ
int Degree(char c) {
	if (c == '(')
		return 5;
	else if (c == '^')
		return 4;
	else if (c == '*'||c =='/'||c == '%')
		return 3;
	else if (c == '+')
		return 2;   // �൱��q^p
	else if (c == '-'||c == '+')
		return 2;   // �൱��qVp�����ȼ����
	else
		return 0;
}
double Num_case[26];//�����������Ĵ���
void Turn_to_letter(string &s) { //��������ת������ĸ
	memset(Num_case,0,sizeof(Num_case));//��ʼ��Ϊ0
	string ans;//��Ϊ�𰸹���
	char temp_letter='a';
	for(int i=0; i<s.size(); i++) {
		if(s[i]>='0'&&s[i]<='9') {
			Num_case[temp_letter-'a']=Num_case[temp_letter-'a']*10+s[i]-'0';//�ַ�ת���� ��ǰ�����λȨ++
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
string MidToPost(string &c) {    //����ʽ��Ӧ�ĺ�׺���ʽ
	stack<char> s;           //�ַ�����ȥ�ֶ�ȥ�ո�
	string q="";
	int n = c.size() ;
	for (int i = 0; i<n; i++) {
		if (c[i] != ' ') {   // ��ȥ�ո�
			// ���������������ֱ�Ӽ��뵽�����У��ö������ź�׺���ʽ
			if (c[i] >='a'&&c[i]<='z') {
				q += c[i];
			} else if (!s.size()) {
				s.push(c[i]);// ���ջΪ�գ����������ֱ����ջ
			} else if (c[i] == ')') {
				// ����������ţ��򵯳���Ӧ������ǰ�����е������ �����뵽������
				while (s.top() != '(') {
					q += s.top();
					s.pop();
				}
				s.pop();      // ����������
				continue;//
			} else if (Degree(s.top()) == 5 || (Degree(c[i]) > Degree(s.top()))) {
				s.push(c[i]);  // ���ջ���������ţ����ߵ�ǰ���ȼ��ߣ�����ջ
			} else if (Degree(s.top()) != 5 && Degree(c[i]) <= Degree(s.top())) {
				q += s.top();
				s.pop();              // ������������û��ջ�����������ߣ���ջ
				while (!s.empty() && Degree(s.top()) != 6 && Degree(c[i]) <= Degree(s.top())) {
					q+=s.top();  // ��ջ�е����ȵ�ǰ���ȼ��ߵ������
					s.pop();
				}
				s.push(c[i]);  //����ǰ��������뵽����
			}
		}
	}
	while (!s.empty()) {
		q += s.top();      // ���ջ��������Ԫ�ص������뵽����
		s.pop();
	}
	c=q;
	return q;
}

//�˲������������׺���ʽ
int GetValuePost(string q) {
	double ans=Num_case[0];//��
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
