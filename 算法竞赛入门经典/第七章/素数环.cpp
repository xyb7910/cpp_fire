#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 20;
int n;
int a[N];
bool vis[N];

bool is_prime(int x) {
    if(x < 2) return false;
    for (int i = 2; i <= x / i; i ++) 
        if(x % i == 0) 
            return false;
    return true;
}

void dfs(int u) {
    if(u == n && is_prime(a[0]+ a[n - 1])) { // 对于 dfs 先判断递归的出口，个数等于 n 并且 最后一个元素和第一个元素之和为 质数
        // 输出 n 个元素
        for (int i = 0; i < n; i ++) printf("%d ", a[i]);
        puts("");
        return ;
    }

    for (int i = 2; i <= n; i ++) {
        if(!vis[i] && is_prime(i + a[u - 1])) {
            a[u] = i;
            vis[i] = true;
            dfs(u + 1);
            vis[i] = false;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}