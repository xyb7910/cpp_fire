#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	// 分钟： 60 - b + d
	// 小时： (a - c - 1) * 60
	cout << (c - 1 - a) * 60 + 60 - b + d << endl;
	return 0;
}