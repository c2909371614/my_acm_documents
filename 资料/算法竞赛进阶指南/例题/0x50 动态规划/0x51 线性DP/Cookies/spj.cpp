#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std; 
//һЩ����
const int ACCEPT = 0;
const int WRONG_ANSWER = 1;
//fstd ��׼��� fout ѡ����� fin ��׼����
FILE *fstd,*fout,*fin;
int n, m, ans, val, c[32], g[32];

//ִ�бȽϲ�����
bool DoCompare(){
    fscanf(fin, "%d%d", &n, &m);
    for (int i = 1; i <= n; i++) fscanf(fin, "%d", &g[i]);
    fscanf(fstd, "%d", &ans);
    fscanf(fout, "%d", &val);
    // �𰸲��� 
    if (ans != val) return false;
    for (int i = 1; i <= n; i++) {
		fscanf(fout, "%d", &c[i]);
		// ÿ�����ӷֵ������������ 
		if (c[i] <= 0) return false;
		m -= c[i];
	}
	// ����û�з��� 
	if (m) return false;
	// ��鷽����Թ��ֵ�Ƿ���������ֵ 
    for (int i = 1; i <= n; i++) {
    	int cnt = 0;
    	for (int j = 1; j <= n; j++) if (c[j] > c[i]) cnt++;
    	val -= cnt * g[i];
    }
	return val == 0;
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
