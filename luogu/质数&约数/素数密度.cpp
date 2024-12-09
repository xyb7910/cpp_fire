#include <bits/stdc++.h>
/*
整体思路：先预处理出来1e5之内的质数，然后用筛选出来的质数把它的倍数筛去
一定要用质数去筛，不然会违背欧拉筛的本质。
如何确保最小呢？从前往后选择，必然最小。
*/
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int primes[N], cnt;      
bool st[N];
void get_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (!st[i]) primes[cnt++] = i;
        for (int j = 0; primes[j] * i <= n; j++) {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0) break;
        }
    }
}
const int M = 10000010;
int a[M];
int main() {
    get_primes(50000); 
    LL L, R;
    cin >> L >> R;
    if (L <= 1) L = 2;
    for (int i = 0; i < cnt; i++) {
        LL start = max(2ll, (L - 1) / primes[i] + 1) * primes[i];
        for (LL j = start; j <= R; j += primes[i]) a[j - L] = 1; 
    }
    int ans = 0;
    for (LL i = L; i <= R; i++) if (!a[i - L])ans++;
    printf("%d", ans);
    return 0;
}