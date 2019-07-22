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
int n, m, k, a[20][20], v[20][20], ans, val;

//ִ�бȽϲ�����
bool DoCompare(){
    fscanf(fin, "%d%d%d", &n, &m, &k);
    for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= m; j++) fscanf(fin, "%d", &a[i][j]);
    fscanf(fstd, "%*s%*s%d", &ans);
    fscanf(fout, "%*s%*s%d", &val);
    // �𰸲��� 
    if (val != ans) return false;
    for (int i = 1; i <= k; i++) {
    	int x, y; fscanf(fout, "%d%d", &x, &y);
    	// ����Խ��������ظ� 
    	if (x < 1 || y < 1 || x > n || y > m || v[x][y]) return false;
    	v[x][y] = 1;
    	val -= a[x][y];
    }
    // ����ĸ��Ӽ����������ڴ� 
    if (val) return false;
    // ���͹�� 
    for (int i = 1; i <= n; i++) {
    	int cnt = 0, l = m, r = 1;
    	for (int j = 1; j <= m; j++)
    		if (v[i][j]) cnt++, l = min(l, j), r = max(r, j);
    	if (cnt == 0) continue;
    	// ����ĸ�����һ���ﲻ���� 
    	if (r - l + 1 != cnt) return false;
    }
    for (int j = 1; j <= m; j++) {
    	int cnt = 0, l = n, r = 1;
    	for (int i = 1; i <= n; i++)
    		if (v[i][j]) cnt++, l = min(l, i), r = max(r, i);
    	if (cnt == 0) continue;
    	// ����ĸ�����һ���ﲻ���� 
    	if (r - l + 1 != cnt) return false;
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
