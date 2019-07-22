#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
using namespace std;
//һЩ����
const int ACCEPT = 0;
const int WRONG_ANSWER = 1;
//fstd ��׼��� fout ѡ����� fin ��׼����
FILE *fstd,*fout,*fin;
int n;
vector<int> chosen; // ��ѡ�����
unordered_map<string, bool> h;

void calc(int x) {
	if (x == n + 1) { // ����߽�
		string s;
		for (int i = 0; i < chosen.size(); i++) {
			if (i > 0) s += ' ';
			if (chosen[i] < 10) s += chosen[i] + '0';
			else s += chosen[i]/10 + '0', s += chosen[i]%10 + '0';
		}
		h[s] = 1;
		return;
	}
    //"��ѡx"��֧
	calc(x + 1); // ���������
	//"ѡx"��֧
	chosen.push_back(x); // ��¼x�ѱ�ѡ��
	calc(x + 1); // ��������� 
	chosen.pop_back(); // ׼�����ݵ���һ����֮ǰ����ԭ�ֳ�
}

//ִ�бȽϲ�����
bool DoCompare(){
    fscanf(fin, "%d", &n);
    calc(1);
    char str[51];
    while(fgets(str, 50, fout) != NULL) {
    	int len = strlen(str);
    	while(len > 0 && (str[len - 1] < '0' || str[len - 1] > '9')) len--;
    	str[len] = 0;
    	if(h.find(str) == h.end()) return false;
    	h.erase(str);
    }
    return !h.size();
}

int main(int argc, char* argv[])
{
    if(argc!=4){
        printf("�������� %d",argc);
        return -1;
    }

    //���ļ�
    if(NULL==(fstd=fopen(argv[1],"r"))){
        return -1;
    }
    if(NULL==(fout=fopen(argv[2],"r"))){
        return -1;
    }
    if(NULL==(fin=fopen(argv[3],"r"))){
        return -1;
    }

    if(DoCompare()){
        return ACCEPT;
    }else{
        return WRONG_ANSWER;
    }
}
