#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
int n;
int a[N];

int main() {
    cin >> n;
    for (auto& i : a) cin >> i;
    sort(a, a + n);
    int day = 1, l = 0;
    while (l < n) {
        if(a[l] >= day) day ++;
        l ++;
    }
    cout << day - 1;
    return 0;
}