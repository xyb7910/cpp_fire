/*
* @Author: Yanpb
* @Date:   2025-01-03 18:30:58
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-03 18:35:31
*/
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int main() {
    int n;
    std::cin >> n;
    std::vector<std::string> instructions(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> instructions[i];
    }
    int warnings = 0;
    for (int i = 0; i < n; ++i) {
        std::string currentInstruction = instructions[i];
        std::unordered_map<std::string, int> countMap;
        for (int j = 0; j < i; ++j) {
            countMap[instructions[j]]++;
        }
        int currentCount = countMap[currentInstruction];
        int otherCount = 0;
        for (const auto& pair : countMap) {
            if (pair.first!= currentInstruction) {
                otherCount += pair.second;
            }
        }
        if (currentCount > otherCount) {
            warnings++;
        }
    }
    std::cout << warnings << std::endl;
    return 0;
}