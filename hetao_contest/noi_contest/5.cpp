#include <iostream>
#include <vector>
#include <unordered_map>

int longestUniqueSublistLength(const std::vector<int>& nums) {
    std::unordered_map<int, int> indexMap; 
    int max_length = 0;
    int start = 0; 

    for (int i = 0; i < nums.size(); ++i) {
        if (indexMap.find(nums[i]) != indexMap.end() && indexMap[nums[i]] >= start) {
           
            start = indexMap[nums[i]] + 1; 
        }
        indexMap[nums[i]] = i; 
        max_length = std::max(max_length, i - start + 1); 
    }

    return max_length;
}

int main() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for (int i = 0; i < N; ++i) {
        std::cin >> A[i];
    }

    std::cout << longestUniqueSublistLength(A) << std::endl;

    return 0;
}