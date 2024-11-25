#include <iostream>
const int N = 2e5 + 10;
int a[N], b[N];
int n, ans;
std::string s;

int main() {
	std::cin >> n;
	std::cin >> s;
	a[0] = s[0] == '1' ? 1 : 0;
	for (int i = 1; i < n; i ++) {
		a[i] = s[i] == '1' ? a[i - 1] + 1 : 0;
	}
	b[n - 1] = s[n - 1] == '2' ? 1 : 0;
	for (int i = n - 2; i >= 0; i --) {
		b[i] = s[i] == '2' ? b[i + 1] + 1 : 0;
	}
	for (int i = 0; i < n; i ++) {
		if(s[i] == '/') {
			int cnt1 = i == 0 ? 0 : a[i - 1];
			int cnt2 = i == n - 1 ? 0 : b[i + 1];
			ans = std::max(ans, std::min(cnt1, cnt2) * 2 + 1);
		}
	}
	std::cout << ans << std::endl;
	return 0;
}