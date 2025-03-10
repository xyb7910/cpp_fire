#include <iostream>

using namespace std;

int n;
int sum(int cur, int s) {
    if(cur <= n) {
        return sum(cur + 1, s + cur);
    } else {
        return s;
    }
}

int main() {
    cin >> n;
    // 递归从1开始 总和从0开始
    cout << sum(1, 0);
    return 0;
}
