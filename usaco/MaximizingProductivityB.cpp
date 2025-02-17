#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
/*
s表示起床时间
c数组表示关门时间，t表示访问时间
会在 t + s 的时刻访问农场i
问是否可以在 s 起床，访问 v 个农场 **严格早于**
s + t < c ==> s < c - t
*/
const int N = 2e5 + 10;
int n, q, v, s;
int c[N], t[N];
int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i ++) cin >> c[i];
    for (int i = 0; i < n; i ++) {
        cin >> t[i];
        c[i] -= t[i];
    } 
    sort(c, c + n);
    while(q --) {
        cin >> v >> s;
        int idx = upper_bound(c, c + n, s) - c;
        int re = n - idx;
        cout << (re >= v ? "YES" : "NO") << endl;
    }
    return 0;
}