/*
* @Author: Yanpb
* @Date:   2025-01-19 09:22:29
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-19 09:22:40
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

const int N =  5e5 + 10;
int a[N];

int main()
{
    int n; cin >> n;
    LL ans = 0;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
        ans += upper_bound(a + 1, a + i + 1, a[i] >> 1) - a - 1;
    }
    cout << ans << endl;
    return 0;
}