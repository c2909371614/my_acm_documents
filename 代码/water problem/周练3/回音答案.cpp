
#include"cstdio"
#include"cstring"
#include"iostream"
 
using namespace std;
 
char s[20005];
 
int main()
{
    while(cin>>s)
    {
        int len=strlen(s);
        for(int i=0;i<len;)
        {
            cout << s+i; //���ַ����ӵ�iλ���
            cout << "~" << endl;
            if(s[i] >='0'&&s[i]<='9') //֮ǰûע������wrong��һ��
            {
                i++;
            }
            else if(isalpha(s[i])) //ֱ���ж�s[i] <= 'Z' && s[i] >= 'A' || s[i] <= 'z' && s[i] >= 'a'���һЩ
            {
                i++;
            }
            else
            {
                i += 2;
            }
        }
    }
    return 0;
}

