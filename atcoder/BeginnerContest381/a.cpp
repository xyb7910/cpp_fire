#include <iostream>

using namespace std;

string s;
int n;

int main() {
	cin >> n;
	cin >> s;
	int n = s.size();
	// 首先判断字符串的长度是都为奇数
	if(!(n & 1)) {
		puts("No");
		return 0;
	}
	// 判断最中间的是不是 '/'
	int mid = n >> 1;
	if(s[mid] != '/') {
		puts("No");
		return 0;
	}
	// 判断前面是否全为 1
	for (int i = 0; i < mid; i ++) {
		if(s[i] != '1') {
			puts("No");
			return 0;
		}
	}
	// 判断后面是否全为 2
	for (int i = mid + 1; i < n; i ++) {
		if(s[i] != '2') {
			puts("No");
			return 0;
		}
	}
	puts("Yes");
	return 0;
}