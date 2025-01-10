#include <iostream>

const int N = 2e5 + 10;

int n;
int dp[N], num[N];

// dp[i] 表示以当下标i为结尾的所有子数组的最大和

int main() {
	std::cin >> n;
	for (auto a : num) std::cin >> a;
	dp[0] = num[0];
	for (int i = 0; i < n; i ++) {
		dp[i] = std::max(dp[i - 1] + num[i], num[i]);
	}
	for (int i = 0; i < n; i ++)  std::cout << num[i] << " ";
		// std::cout << dp[i] << " ";
	return 0;
}