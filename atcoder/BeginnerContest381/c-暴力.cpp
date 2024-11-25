#include <iostream>

/*
如果暴力枚举的话，时间复杂度为 O(n ^ 2)。
可以先枚举'/'，然后令其前面1的个数为cnt1，后面2的个数为cnt2
最终答案为：1 + min(cnt1, cnt2) * 2;
*/
int n, ans;
std::string s;

int main() {
	std::cin >> n;
	std::cin >> s;
	
	for (int i = 0; i < n; i ++) {
		if(s[i] == '/') {
			int pos = i - 1;
			while(pos >= 0 && s[pos] == '1') pos --;
			int cnt1 = i - pos - 1;
			pos = i + 1;
			while(pos < n && s[pos] == '2') pos ++;
			int cnt2 = pos - i - 1;
			ans = std::max(ans, 2 * std::min(cnt1, cnt2) + 1);
		}
	}
	std::cout << ans << std::endl;
	return 0;
}