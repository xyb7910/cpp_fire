/*
* @Author: Yanpb
* @Date:   2025-02-08 16:59:28
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-08 16:59:52
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int res;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i <= n; i ++) {
        for (int j = 0; j <= n; j ++) {
            for (int k = 0; k <= n; k ++) {
                if((i + j) % 2 == 0 && (j + k) % 3 == 0 && (i + j + k) % 5 == 0)
                    res = max(res, i + j + k);
            }
        }
    }
    cout << res;
    return 0;
}