#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;
int n, cnt;
bool st[N], vis[N];
int primes[N], a[N];

void get_primes(int n) {
    for (int i = 2; i < n; i ++) {
        if(!st[i]) primes[cnt ++] = i;
        for (int j = 0; primes[j] <= n / i; j ++) {
            st[primes[j] * i] = true;
            if(i % primes[j] == 0) break;
        }
    }
}

void dfs(int cur) {
    // 判断输出条件 个数等于要求的个数 && 首尾元素均为质数
    if(cur == n && !st[a[0] + a[n - 1]]) {
        for (int i = 0; i < n; i ++) printf("%d ", a[i]);
        puts("");
    }

    for (int i = 2; i <= n; i ++) {
        if(!vis[i] && !st[i + a[cur - 1]]) {
            a[cur] = i;
            vis[i] = true;
            dfs(cur + 1);
            vis[i] = false;
        }
    }
}

int main() {
    cin >> n;
    get_primes(20);
    dfs(1);
    return 0;
}