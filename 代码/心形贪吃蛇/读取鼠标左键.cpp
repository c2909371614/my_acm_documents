
#include<iostream>
#include<windows.h>
 
#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) //��Ҫ�ģ����Ǳ������� 
 
using namespace std;
 
int main(){
	while(1){
		printf("�������Ƿ��£�");
		if(KEY_DOWN(VK_LBUTTON))printf("��");
		else printf("��");
		printf("\n");
		
		printf("����Ҽ��Ƿ��£�");
		if(KEY_DOWN(VK_RBUTTON))printf("��");
		else printf("��");
		printf("\n");
		
		printf("�����ּ��Ƿ��£�");
		if(KEY_DOWN(VK_MBUTTON))printf("��");
		else printf("��");
		printf("\n");
		
		Sleep(20);//ѭ��ʱ��������ֹ̫ռ�ڴ� 
		system("cls");//���� 
	}
 
	return 0;
}

