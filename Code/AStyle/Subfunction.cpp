#include"head.h"
int f(char c) {
	if (c == '(') return 4;
	if (c == '!') return 3;
	if (c == '&') return 2;   // �൱��*
	if (c == '|') return 1;   // �൱��+�����ȼ����
	else
		return 0;
}

bool f2(char c) {
	if (c == 'F') return false;   //  F�൱��0
	else return true;            //  V�൱��1
}

string MidToPost(char* c) {    //����ʽ��Ӧ�ĺ�׺���ʽ
	stack<char> s;           //�ַ�����ȥ�ֶ�ȥ�ո�
	string q="";
	int n = strlen(c);
	for (int i = 0; i<n; i++) {
		if (c[i] != ' ') {   // ��ȥ�ո�
			// ���������������ֱ�Ӽ��뵽�����У��ö������ź�׺���ʽ
			if (c[i] == 'F' || c[i] == 'V') {
				q += c[i];
			} else if (c[i] == '!'&&!s.empty() && s.top() == '!') {
				s.pop();     // �������������ջ��Ҳ��!��ôֱ�ӵ�����ջ
			} else if (!s.size()) {
				s.push(c[i]); // ���ջΪ�գ����������ֱ����ջ
			} else if (c[i] == ')') {
				// ����������ţ��򵯳���Ӧ������ǰ�����е������ �����뵽������
				while (s.top() != '(') {
					q += s.top();
					s.pop();
				}
				s.pop();      // ����������
				continue;
			} else if (f(s.top()) == 4 || (f(c[i]) > f(s.top()))) {
				s.push(c[i]);  // ���ջ���������ţ����ߵ�ǰ���ȼ��ߣ�����ջ
			} else if (f(s.top()) != 4 && f(c[i]) <= f(s.top())) {
				q += s.top();
				s.pop();              // ������������û��ջ�����������ߣ���ջ
				while (!s.empty() && f(s.top()) != 4 && f(c[i]) <= f(s.top())) {
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
	return q;
}

