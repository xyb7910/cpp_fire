#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

/*
曼哈顿距离(出租车距离)的使用：
(x1, y1) (x2, y2) 的曼哈顿距离等于 |x1 - x2| + |y1 - y2|
*/

int main() {
	char c; cin >> c;
	int n = 5;
	int dx = n / 2, dy = n / 2;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if(abs(i - dx) + abs(j - dy) <= n / 2) cout << c;
			else cout << " ";
		}
		cout << endl;
	}
	return 0;
}