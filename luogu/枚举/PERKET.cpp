/*
* @Author: Yanpb
* @Date:   2025-02-06 10:21:37
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-06 10:21:48
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> ingredients(n);
    
    for (int i = 0; i < n; ++i) {
        cin >> ingredients[i].first >> ingredients[i].second;
    }
    
    int min_diff = INT_MAX;
    
    // 枚举所有可能的配料组合
    for (int mask = 1; mask < (1 << n); ++mask) {
        int total_s = 1; // 酸度的乘积
        int total_b = 0; // 苦度的总和
        
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                total_s *= ingredients[i].first;
                total_b += ingredients[i].second;
            }
        }
        
        int diff = abs(total_s - total_b);
        if (diff < min_diff) {
            min_diff = diff;
        }
    }
    
    cout << min_diff << endl;
    
    return 0;
}