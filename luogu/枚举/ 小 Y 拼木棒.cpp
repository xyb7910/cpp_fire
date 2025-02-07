/*
* @Author: Yanpb
* @Date:   2025-02-07 10:19:35
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-07 10:20:02
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
/*
先选择出两个长度一样的A, B，在选出两根使得长度之和等于A
*/
typedef long long LL;
const int N = 1e5 + 10, MOD = 1e9 + 7;
LL n, res;
int l[N], cnt[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> l[i];
        cnt[l[i]] ++;
    }
    sort(l, l + n);
    int st = l[0], ed = l[n - 1];
    for (int i = st + 1; i <= ed; i ++) {
        if(cnt[i] >= 2) {
            for (int j = st; j <= i / 2; j ++) {
                if(j != i - j) res += cnt[i] * (cnt[i] - 1) / 2 * cnt[j] * cnt[i - j] % MOD;
                else if(cnt[j] >= 2 && 2 * j == i) res += cnt[i] * (cnt[i] - 1) / 2 * cnt[i / 2] * (cnt[i / 2] - 1) / 2 % MOD;
            }
            res %= MOD;
        }
    }
    cout << res;
    return 0;
}