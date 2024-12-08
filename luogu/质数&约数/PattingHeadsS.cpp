#include <iostream>
#include <vector>
#include <algorithm>

const int MAX_NUM = 1000000;

// 预处理所有可能的约数
void preprocessDivisors(std::vector<int>& divisorsCount) {
    for (int i = 1; i <= MAX_NUM; ++i) {
        for (int j = i; j <= MAX_NUM; j += i) {
            divisorsCount[j]++;
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<int> cowNumbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> cowNumbers[i];
    }

    // 创建并初始化一个数组来存储每个数字的约数数量
    std::vector<int> divisorsCount(MAX_NUM + 1, 0);
    preprocessDivisors(divisorsCount);

    // 对于每头奶牛，输出它需要拍打的其他奶牛数量
    for (int number : cowNumbers) {
        std::cout << divisorsCount[number] << std::endl;
    }

    return 0;
}