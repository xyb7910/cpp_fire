/*
* @Author: Yanpb
* @Date:   2025-02-07 15:04:46
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-07 15:04:50
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }
    
    for (int k = 1; k < (1 << n); ++k) {
        vector<int> subset;
        for (int i = 0; i < n; ++i) {
            if (k & (1 << i)) {
                subset.push_back(nums[i]);
            }
        }
        for (size_t j = 0; j < subset.size(); ++j) {
            if (j > 0) cout << " ";
            cout << subset[j];
        }
        cout << endl;
    }
    
    return 0;
}