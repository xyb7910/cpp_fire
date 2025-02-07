/*
* @Author: Yanpb
* @Date:   2025-02-07 10:20:24
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-07 10:49:02
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 5e5 + 10;
int n;
int cnt[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        cnt[x] ++;
    }
    LL res = 0;
    for (int i = 1; i <= N; i ++) {
        for (int j = 2; i * j <= N; j ++) {
            res += cnt[i] * cnt[i * j];
        }
        res += cnt[i] * (cnt[i] - 1);
    }
    cout << res;
    return 0;
}