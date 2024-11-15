#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArraySum(const std::vector<int>& nums) {
    int maxSoFar = nums[0];
    int currentMax = nums[0];

    for (size_t i = 1; i < nums.size(); ++i) {
        currentMax = std::max(nums[i], currentMax + nums[i]);
        maxSoFar = std::max(maxSoFar, currentMax);
    }

    return maxSoFar;
}

int main() {
    int n;
    std::cin >> n; // 读取天数

    std::vector<int> moodValues(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> moodValues[i]; // 读取心情值
    }

    // 计算并输出最大的心情值总和
    std::cout << maxSubArraySum(moodValues) << std::endl;

    return 0;
}