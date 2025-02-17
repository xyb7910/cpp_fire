#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int  N = 1e5 + 10;
typedef long long i64;
i64 n, x, ans;
int a[N];

int main() {
    cin >> n >> x;
    for (auto& s : a) cin >> s;
    
    for (int i = 0; i < n - 1; i ++) {
        if(a[i + 1] + a[i] > x) {
            int re = a[i] + a[i + 1] - x;
            // 优先吃掉后面盒子的糖果
            if(a[i + 1] >= re) a[i + 1] -= re;
            else {
                // 后面的糖果不够吃
                a[i] -= re - a[i + 1];
                a[i + 1] = 0;
            }
            ans += re;
        }
    }
    cout << ans;
    return 0;
}