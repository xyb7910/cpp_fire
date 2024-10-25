#include <iostream>
#include <vector>

// 定义取模常量
const int MOD = 1000000007;

int main() {
    // 读取输入的台阶数
    int n;
    std::cin >> n;
    
    // 定义一个动态规划数组，我们最多需要到n的数值
    std::vector<long long> dp(n + 1, 0);
    
    // 初始化基本情况
    if (n >= 0) dp[0] = 1;
    if (n >= 1) dp[1] = 1;
    if (n >= 2) dp[2] = 2;
    if (n >= 3) dp[3] = 4;
    
    // 从第4个台阶开始计算到n的每一个台阶的方法数
    for (int i = 4; i <= n; ++i) {
        dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % MOD;
    }
    
    // 输出第n个台阶的方法数
    std::cout << dp[n] << std::endl;
    
    return 0;
}