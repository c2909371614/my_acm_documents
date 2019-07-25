/*实现重定向，把预定义的标准流文件定向到由path指定的文件中。标准流文
件具体是指stdin、stdout和stderr。其中stdin是标准输入流，默认为键盘；
stdout是标准输出流，默认为屏幕；stderr是标准错误流，
一般把屏幕设为默认。通过调用freopen，就可以修改标准流文件的默认值，实现重定向。*/
#include <stdio.h>
#include <iostream>
using namespace std;
class Read_data {
	public:
		Read_data() {
			freopen("in.txt","r",stdin); //输入重定向，输入数据将从in.txt文件中读取
			freopen("out.txt","w",stdout); //输出重定向，输出数据将保存在out.txt文件中
		}
		~Read_data(){
			fclose(stdin);//关闭文件
			fclose(stdout);//关闭文件
		} 
};
int main() {
	int a,b;

	while(cin>> a >> b)
		cout<< a+b <<endl; // 注意使用endl
	
	return 0;
}
