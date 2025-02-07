/*
* @Author: Yanpb
* @Date:   2025-02-07 10:20:24
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-07 16:49:14
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 5e5 + 10;
LL n, x;
LL cnt[N];
int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        cin >> x;
        cnt[x] ++;
    }
    LL res = 0;
    for (int i = 1; i <= N; i ++) {
        res += cnt[i] * (cnt[i] - 1);
        for (int j = i + i; i * j <= N; j += i) {
            res += cnt[i] * cnt[j];
        }
    }
    cout << res;
    return 0;
}