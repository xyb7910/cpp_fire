/*
* @Author: Yanpb
* @Date:   2025-04-23 17:15:44
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-23 17:15:52
*/
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string removeKDigits(string num, int k) {
    vector<char> stack;
    for (char digit : num) {
        while (!stack.empty() && k > 0 && stack.back() > digit) {
            stack.pop_back();
            k--;
        }
        stack.push_back(digit);
    }
    // Remove remaining k digits from the end
    while (k > 0 && !stack.empty()) {
        stack.pop_back();
        k--;
    }
    // Construct the result string
    string result;
    for (char digit : stack) {
        result += digit;
    }
    // Remove leading zeros
    size_t nonZeroIndex = 0;
    while (nonZeroIndex < result.size() && result[nonZeroIndex] == '0') {
        nonZeroIndex++;
    }
    result = result.substr(nonZeroIndex);
    return result.empty() ? "0" : result;
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    cout << removeKDigits(n, k) << endl;
    return 0;
}