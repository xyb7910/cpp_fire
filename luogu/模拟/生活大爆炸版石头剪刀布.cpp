#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 210;
int n, n_a, n_b;
int a[N], b[N];
int ans_a, ans_b; 
int main() {
    cin >> n >> n_a >> n_b;
    for (int i = 0; i < n_a; i ++) cin >> a[i];
    for (int i = 0; i < n_b; i ++) cin >> b[i];
    for (int i = 0; i < n; i ++) {
        int p = a[i % n_a], q = b[i % n_b];
        // 两个人的拳一样
        if(p == q) continue;
        
        if(p == 3 && q == 4) ans_a ++;
        else if(p - q == 1 && q != 3) ans_a ++;
        else if(p - q == -2) ans_a ++;
        else if(p == 0 && q == 3) ans_a ++;
        else if(p == 4 && q == 0) ans_a ++;
        else if(p == 4 && q == 1) ans_a ++;
        else ans_b ++;
    }
    cout << ans_a << " " << ans_b;
    return 0;
}