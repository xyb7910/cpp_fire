#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> colors(n);
    vector<int> weights(n);

    for (int i = 0; i < n; ++i) {
        cin >> colors[i];
    }

    for (int i = 0; i < n; ++i) {
        cin >> weights[i];
    }

    vector<pair<int, int>> mergedGarbage; // 颜色, 总重量

    // 合并颜色相同的垃圾堆
    int currentColor = colors[0];
    int currentWeight = weights[0];

    for (int i = 1; i < n; ++i) {
        if (colors[i] == currentColor) {
            currentWeight += weights[i];
        } else {
            mergedGarbage.push_back({currentColor, currentWeight});
            currentColor = colors[i];
            currentWeight = weights[i];
        }
    }
    
    // 最后一组垃圾堆合并
    mergedGarbage.push_back({currentColor, currentWeight});

    int mergedPilesCount = mergedGarbage.size();
    int totalTrips = 0;

    for (const auto& pile : mergedGarbage) {
        totalTrips += (pile.second + m - 1) / m; // 计算运输次数
    }

    cout << mergedPilesCount << endl;
    cout << totalTrips << endl;

    return 0;
}