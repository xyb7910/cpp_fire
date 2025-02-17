#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long i64;
const  int N = 310;
int n;
i64 ans;
int h[N];

i64 calcu(int num1, int num2) {
    return ((num1 - num2) * (num1 - num2));
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> h[i];
    sort(h + 1, h + 1 + n);
    int i = 0, j = n;
    while(i < j) {
        ans += calcu(h[j], h[i]);
        ++ i;
        ans += calcu(h[i], h[j]);
        -- j;
    }
    cout << ans;
    return 0;
}