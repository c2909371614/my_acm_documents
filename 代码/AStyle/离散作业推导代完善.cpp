#include<bits/stdc++.h>
using namespace std;

string tihuan(int l,int r,char[]) {

}
int main() {
	queue<char> que;
	stack<char> stk;
	char a[]="";
	char str[10000];
	int bi,ei;
	cin>>str;
	char ans[10000];
	for(int i=0; i<strlen(str); i++) { //遍历预处理字符
		char fin[1000];
		char fin2[1000];
		if(str[i]=='^') {
			fin[0]='~';//在字符前加~和括号（
			fin[1]='(';
			int l=i,r=i;//l为左指针 r为右指针
			if(str[l-1]==')') {
				int count=2;
				l--;
				while(str[l]!='(') {
					stk.push(str[l]);//
					//cout<<stk.top()<<endl;
					l--;
				}
				bi=l;
				while(!stk.empty()) {
					fin[count++]=stk.top();
					stk.pop();
				}
			} else {
				fin[1]=str[l-1];
				bi=l-1;
			}
			if(str[r+1]=='(') {
				r+=1;
				int count=0;
				while(str[r]!=')') {
					fin2[count++]=str[r];
					r++;
				}
				ei=r;
				fin2[count]=')';
			} else {
				fin2[0]=str[r+1];
				ei=r+1;
			}
			for(int j=0; j<bi; j++)
				que.push(str[j]);
			for(int j=0; j<strlen(fin); j++)
				que.push(fin[j]);
			que.push('|');
			for(int j=0; j<strlen(fin2); j++)
				que.push(fin2[j]);
			for(int j=ei+1; j<strlen(str); j++)
				que.push(str[j]);
			int s=que.size();
			for(int j=0; j<s; j++) {
				str[j]=que.front();
				que.pop();
			}
		}
	}
	cout<<str<<endl;
//	int len=strlen(str);
//	char str2[10000];
//	strcpy(str2,str);
//	for(int i=0;i<len;i++){
//		char fin[1000];
//		if(str2[i]=='~' && str2[i+1]=='('){
//			bi=i-1;
//			int j=i+2,cnt=0;
//			while(str2[j]!=')'){
//				if(str2[j]>='a' && str2[j]<='z') {
//					fin[cnt++]='~';
//					fin[cnt++]=str[j];
//				}
//				else if(str2[j]=='|') fin[cnt++]='&';
//				else if(str2[j]=='&')fin[cnt++]='|';
//				else fin[cnt++]=str2[j];
//				j++;
//			}
//			ei=j+1;
//			for(int j=0;j<=bi;j++)
//				que.push(str2[j]);
//			for(int j=0;j<strlen(fin);j++)
//				que.push(fin[j]);
//			for(int j=ei;j<len;j++){
//				que.push(str2[j]);
//			}
//			strcpy(str2,a);
//			int s=que.size();
//			for(int j=0;j<s;j++){
////				cout<<que.front();
//    			ans[j]=que.front();
//    			que.pop();
//			}
////			cout<<endl;
//			cout<<ans<<endl;
//			strcpy(str2,a);
//			strcpy(str2,ans);
//		}
//	}
//	int len1=strlen(ans);
//	for(int i=0;i<len1;i++){
//		if(ans[i]=='~' && ans[i+1]=='~'){
//          len1=len1-2;
//			for(int j=i;j<len1;j++) {
//				ans[j]=ans[j+2];
//			}
//		}
//	}
//	for(int i=0;i<len1;i++){
//		cout<<ans[i];
//	}
//
//
}
