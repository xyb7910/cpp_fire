/*
* @Author: Yanpb
* @Date:   2025-02-02 15:19:37
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-02 15:20:10
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int n, r;
int a[30]; 

void dfs(int u, int start) {
    if (u > r) {
        for (int i = 1; i <= r; i++) {
            printf("%3d", a[i]);
        }
        puts("");
        return;
    }

    for (int i = start; i <= n; i++) {
        a[u] = i;
        dfs(u + 1, i + 1); 
    }
}

int main() {
    cin >> n >> r;
    dfs(1, 1);
    return 0;
}