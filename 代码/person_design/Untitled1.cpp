#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
const string pos_file = "click_pos.txt";
void my_click(const string &event, int x_pos, int y_pos) {
	int sw;
	if(event == "left") sw = 'l';
	else if(event == "right") sw = 'r';
	SetCursorPos(x_pos, y_pos);//设置鼠标位置
	switch(sw) {
		case 'l':

			mouse_event(MOUSEEVENTF_LEFTDOWN | MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			break;
		case 'r':
			mouse_event(MOUSEEVENTF_RIGHTDOWN | MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
			break;
	}
}
class Click_mouse {
	private:
		vector<int> x;
		vector<int> y;
		int MIN;
	public:
		Click_mouse(int a = -1, int b = -1) {
			if(b >= 0 && a >= 0)
				x.push_back(a),
				            y.push_back(b);
			MIN = 3600*1000;
			read_pos();
		}
		void read_pos() {
			fstream in(pos_file.c_str(),ios::in);
			int x_pos, y_pos;
			while(in >> x_pos >> y_pos) {
				x.push_back(x_pos);
				y.push_back(y_pos);
			}
			in.close();
		}
		void display() {
			cout << "输入的坐标有:" << endl;
			for(int i = 0; i < x.size(); i++) {
				cout << "(" << x[i] << "," << y[i] << ")" << endl;
			}
		}
		void click() {
			for(int i = 0; i < x.size(); i++) {
				my_click("left", x[i], y[i]);
				Sleep(500); 
				my_click("left", x[i], y[i]);
				
				//my_click("left",x[i], y[i]);
				display();
				i%3==2?Sleep(MIN):Sleep(2000);
			}

		}
};
int main() {
	Click_mouse Q;
	Sleep(1);
	while(true) {
		Q.click();
	}
	return 0;
}

