#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
// 对于任意大于1的自然数n，若n为奇数，则将n变为3n + 1；否则将n变为n的一半，经过若干次变换，一定可以将n变为1。
// 输入 n 输出转换次数

const int N = 1e5 + 10;
typedef long long LL;
int n, cnt;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	while(n > 1) {
		if(n % 2 == 1) n = n * 3 + 1;
		else n /= 2;
		cnt ++;
	}
	cout << cnt << endl;
	return 0;
}