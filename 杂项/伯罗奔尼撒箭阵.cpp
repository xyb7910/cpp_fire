/*
* @Author: Yanpb
* @Date:   2025-04-23 16:56:42
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-23 17:14:00
*/
#include <iostream>
#include <vector>
using namespace std;

int countSequences(int n) {
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; ++i) {
        dp[i] = 1; 
        for (int j = 1; j <= i / 2; ++j) {
            dp[i] += dp[j];
        }
    }
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << countSequences(n) << endl;
    return 0;
}