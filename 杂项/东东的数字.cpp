/*
* @Author: Yanpb
* @Date:   2025-04-17 20:37:34
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-17 21:36:12
*/
#include <iostream>
#include <vector>
using namespace std;

typedef long long i64;

const int MOD = 100000007;

int main() {
    int n, s, a, b;
    cin >> n >> s >> a >> b;
    
    vector<vector<int>> dp(n, vector<int>(n, 0));
    dp[0][0] = 1;
    
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % MOD;
            }
            if (i - 1 >= j) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }
        }
    }
    
    int res = 0;
    for (int t = 0; t < n; ++t) {
        i64 sum = (i64)a * t - (i64)b * (n - 1 - t);
        if ((s - sum) % n == 0) {
            res = (res + dp[n - 1][t]) % MOD;
        }
    }
    
    cout << res << endl;
    return 0;
}