/*
* @Author: Yanpb
* @Date:   2025-05-08 14:06:28
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-05-08 14:29:40
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int a, b;
string s;

int main() {
	cin >> a >> s >> b;
	// 先使用秦九韶算法将 a进制 转化为10进制
	int res = 0;
	for (auto c : s) {
		int digit = 0;
		if(c >= '0' && c <= '9') digit = c - '0';
		else  digit = 10 + c - 'A';
		res = res * a + digit;
	}
	// 再使用短除法将 10进制转化为 b进制
	string ans;
	while(res) {
		int r = res % b;
		if(r >= 0 && r <= 9) ans += '0' + r;
		else ans += r - 10 + 'A';
		res /= b;
	}
	reverse(ans.begin(), ans.end());
	cout << ans;
	return 0;
}