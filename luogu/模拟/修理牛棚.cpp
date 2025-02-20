#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 210;
int m, s, c;
int a[N], b[N];
int main() {
    cin >> m >> s >> c;
    for (int i = 0; i < c; i ++) cin >> a[i];
    sort(a, a + c);
    int res = a[c - 1] - a[0] + 1;
    for (int i = 1; i < c; i ++) b[i] = a[i] - a[i - 1] - 1;
    sort(b + 1, b + c + 1, greater<int>());
    for (int i = 0; i < m; i ++) res -= b[i];
    cout << res;
    return 0;
}