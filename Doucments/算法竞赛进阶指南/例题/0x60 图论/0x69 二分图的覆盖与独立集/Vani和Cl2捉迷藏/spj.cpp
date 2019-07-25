#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
//һЩ����
const int ACCEPT = 0;
const int WRONG_ANSWER = 1;
//fstd ��׼��� fout ѡ����� fin ��׼����
FILE *fstd,*fout,*fin;
int n, m, ans, val;
bool v[210], f[210];
vector<int> ver[210];

bool dfs(int x) {
	f[x] = 1;
	if (v[x]) return true;
	for (int i = 0; i < ver[x].size(); i++) {
		int y = ver[x][i];
		if (f[y]) continue;
		if (dfs(y)) return true;
	}
	return false;
}

//ִ�бȽϲ�����
bool DoCompare(){
	fscanf(fin, "%d%d", &n, &m);
    for (int i = 1; i <= m; i++) {
    	int x, y;
		fscanf(fin, "%d%d", &x, &y);
		ver[x].push_back(y);
	}
    fscanf(fstd, "%d", &ans);
    fscanf(fout, "%d", &val);
    // �𰸲��� 
    if (val != ans) return false;
    for (int i = 1; i <= ans; i++) {
    	int x; fscanf(fout, "%d", &x);
    	// ����Ĳ���㲻�Ϸ������ظ� 
    	if (x < 1 || x > n || v[x]) return false;
    	v[x] = 1;
    }
    for (int i = 1; i <= n; i++) {
    	if (!v[i]) continue;
		memset(f, 0, sizeof(f));
		v[i] = 0;
		// �ܿ�����ĵ� 
    	if (dfs(i)) return false;
    	v[i] = 1;
    }
    return true;
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
