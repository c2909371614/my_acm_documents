/*ʵ���ض��򣬰�Ԥ����ı�׼���ļ�������pathָ�����ļ��С���׼����
��������ָstdin��stdout��stderr������stdin�Ǳ�׼��������Ĭ��Ϊ���̣�
stdout�Ǳ�׼�������Ĭ��Ϊ��Ļ��stderr�Ǳ�׼��������
һ�����Ļ��ΪĬ�ϡ�ͨ������freopen���Ϳ����޸ı�׼���ļ���Ĭ��ֵ��ʵ���ض���*/
#include <stdio.h>
#include <iostream>
using namespace std;
class Read_data {
	public:
		Read_data() {
			freopen("in.txt","r",stdin); //�����ض����������ݽ���in.txt�ļ��ж�ȡ
			freopen("out.txt","w",stdout); //����ض���������ݽ�������out.txt�ļ���
		}
		~Read_data(){
			fclose(stdin);//�ر��ļ�
			fclose(stdout);//�ر��ļ�
		} 
};
int main() {
	int a,b;

	while(cin>> a >> b)
		cout<< a+b <<endl; // ע��ʹ��endl
	
	return 0;
}
