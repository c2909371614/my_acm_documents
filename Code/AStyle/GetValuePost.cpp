#include"head.h"
char GetValuePost(string q) {
	//��׺����ʽ��ֵ
	bool r = true;
	char x, y, ans;
	stack<char> s;
	int n = q.size();
	for (int i = 0; i < n; i++) {
		if (q[i] == 'V' || q[i] == 'F') {
			s.push(q[i]);
		} else {
			if (q[i] == '&') {
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				r == f2(x) && f2(y);
				if (r == 1)
					s.push('V');
				else
					s.push('F');
			} else if (q[i] == '|') {
				x = s.top();
				s.pop();
				y = s.top();
				s.pop();
				r = f2(x) || f2(y);
				if (r == 1)
					s.push('V');
				else
					s.push('F');
			} else {
				x = s.top();
				s.pop();
				if (f2(x) == 1)
					s.push('F');
				else
					s.push('V');
			}
		}
		ans = s.top();

	}
	return ans;
}
