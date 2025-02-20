#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 60;
int n, l, r;
int sum, pos, neg;
int a[N];

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++) {
        cin >> a[i];
        sum += a[i];
    }
    cin >> l >> r;
    if(sum < l * n || sum > r * n) {
        cout << -1;
        return 0;
    }
    for (int i = 0; i < n; i ++) {
        if(a[i] < l) neg += l - a[i];
        if(a[i] > r) pos += a[i] - r;
    }
    cout << (pos > neg ? pos : neg);
    return 0;
}