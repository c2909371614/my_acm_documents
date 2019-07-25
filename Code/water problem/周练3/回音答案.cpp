
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
            cout << s+i; //将字符串从第i位输出
            cout << "~" << endl;
            if(s[i] >='0'&&s[i]<='9') //之前没注意引号wrong了一次
            {
                i++;
            }
            else if(isalpha(s[i])) //直接判断s[i] <= 'Z' && s[i] >= 'A' || s[i] <= 'z' && s[i] >= 'a'会快一些
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

