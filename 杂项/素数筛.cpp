#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e8 + 10;
int primes[N], cnt, n, q;
bool st[N];
int main() {
    scanf("%d%d", &n, &q); 
    st[0] = st[1] = 1; // 0和1需要特殊标记
    // 完成素数筛部分 
    for (int i = 2; i * i <= n; i ++) {
        if(!st[i]) {
            for (int j = 2 * i; j <= n; j += i) {
                st[j] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i ++) {
        if(!st[i]) {
            primes[++ cnt] = i;
        }
    }
    while(q --) {
        int t; 
        scanf("%d", &t);
        printf("%d\n", primes[t]);
    }
    return 0;
}

