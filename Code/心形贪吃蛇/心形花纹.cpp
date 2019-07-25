#include <stdio.h>
#include<windows.h>
int main() {
	while(1){
		for (float y = 1.2f; y > -1.2f; y -= 0.1f) {
        	for (float x = -1.5f; x < 1.5f; x += 0.05f) {
            	float z = x * x + y * y - 1;
            	float f = z * z * z - x * x * y * y * y;
            	putchar(f <= 0.0f ? ".:-=+*#%@"[(int)(f * -8.0f)] : ' ');
        }
        	putchar('\n');
        	Sleep(150);
    }
	}
    
}
