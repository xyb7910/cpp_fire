/*
* @Author: Yanpb
* @Date:   2025-04-26 14:43:57
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-26 14:44:05
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
LL a[N], s = -1;
int main() {
    int n; cin >> n;
    while(n --) {
        LL l, r; cin >> l >> r;
        s = max(s, r);
        a[l] += 1, a[r + 1] -= 1;
    }
    LL res = -1;
    for (int i = 0; i <= s; i ++) {
        a[i] += a[i - 1];
        res = max(res, a[i]);
    }
    cout << res;
    return 0;
}