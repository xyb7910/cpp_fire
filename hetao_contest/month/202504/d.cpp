/*
* @Author: Yanpb
* @Date:   2025-04-25 13:21:52
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-27 14:31:30
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int L, n;
    cin >> L >> n;
    vector<int> x(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i];
    }
    
    int min_time = 0, max_time = 0;
    for (int a : x) {
        int cur_min = min(a, L - a);
        if (cur_min > min_time) {
            min_time = cur_min;
        }
        int cur_max = max(a, L - a);
        if (cur_max > max_time) {
            max_time = cur_max;
        }
    }
    
    cout << min_time << " " << max_time << endl;
    return 0;
}