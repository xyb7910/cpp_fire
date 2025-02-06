/*
* @Author: Yanpb
* @Date:   2025-02-06 10:17:21
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-06 10:17:32
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[10], st[10];

void dfs(int u, int a[], int st[]) {
    if(u > n) {
        for (int i = 1; i <= n; i ++)
            printf("%5d", a[i]);
        puts("");
    }
    
    for (int i = 1; i <= n; i ++)
        if(!st[i]) {
            st[i] = 1;
            a[u] = i;
            dfs(u + 1, a, st);
            st[i] = 0;
        }
    
}

int main() {
    cin >> n;
    dfs(1, a, st);
    return 0;
}