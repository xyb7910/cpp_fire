#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    for (int i = 0; i < n; ++i) std::cin >> b[i];
    
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1, 0));
    
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (a[i - 1] > b[j - 1]) {
                dp[i][j] = std::max(dp[i][j], dp[i - 1][j] + 1);
            }
            dp[i][j] = std::max(dp[i][j], dp[i][j - 1]);
        }
    }
    
    std::cout << dp[n][n] << std::endl;
    return 0;
}