/*
* @Author: Yanpb
* @Date:   2025-02-06 10:22:03
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-06 10:22:12
*/
#include <iostream>
#include <cstring>
#include <algorithm> 
using namespace std;

const int N = 110, M = 2e4 + 10;
int n;
int a[N], st[M];

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // 检查 i + j 是否存在于数组中
            if (std::find(a, a + n, a[i] + a[j]) != a + n && !st[a[i] + a[j]]) {
                res ++;
                st[a[i] + a[j]] = 1;
                // printf("%d + %d = %d\n", a[i], a[j], a[i] + a[j]);
            }
        }
    }
    cout << res;
    return 0;
}