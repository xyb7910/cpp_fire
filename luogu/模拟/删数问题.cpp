#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1010;
string s;
int k;
int a[N];

int main() {
    cin >> s;
    int n = s.size();
    for (int i = 0; i < n; i ++) a[i] = s[i] - '0';
    cin >> k;
    // 先删除 k 次
    for (int q = 0; q < k; q ++) {
        for (int j = 0; j < n; j ++) {
            if(a[j] > a[j + 1]) {
                for (int h = j; h < n; h ++) a[h] = a[h + 1];
                n --;
                break;
            }
        }
    }

    // 去掉前导零
    int start = 0, cnt = 0;
    while(a[cnt] == 0 && start < n - 1) {
        start ++;
        cnt ++;
    }

    for (int i = start; i < n; i ++) cout << a[i];
    return 0;
}