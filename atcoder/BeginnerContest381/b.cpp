#include <iostream>
const int N = 128;
int cnt[N];
int main() {
	std::string s;
	std::cin >> s;
	int n = s.size();
	// 首先判断长度是否为奇数
	if(n & 1) {
		puts("No");
		return 0;
	}
	// 判断相邻的两个字符是否相等
	for (int i = 0; i < n; i += 2) {
		if(s[i] != s[i + 1]) {
			puts("No");
			return 0;
		}
	}
	// 对个数进行判断
	for (int i = 0; i < n; i ++) {
		if(cnt[s[i]] == 2) {
			puts("No");
			return 0;
		}
		cnt[s[i]] ++;
	}
	puts("Yes");
	return 0;
}