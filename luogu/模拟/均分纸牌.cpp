#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1010;
int n;
int a[N];
int total, average, ans;
int main() {
    cin >> n;
    for (auto& e: a) cin >> e, total += e;
    average = total / n;
    for (int i = 0; i < n; i ++) {
        if(a[i] != average) a[i + 1] += a[i] - average, ans++;
    }
    cout << ans;
    return 0;
}