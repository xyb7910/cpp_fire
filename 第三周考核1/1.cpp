#include <iostream>
using namespace std;

const int N = 2e6 + 10;

int n, m;
int t[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i ++) {
        int num;
        cin >> num;
        t[num] ++;
    }
    for (int i = 1; i <= n; i++) {
        while(t[i] --) cout << i << " ";
    }
    return 0;
}