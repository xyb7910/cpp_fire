/*
* @Author: Yanpb
* @Date:   2025-02-06 10:19:02
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-06 10:19:16
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 10010;
int a[N];
int n, m;
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++) scanf("%d", &a[i]);
    
    // 手动模拟 next_permutation
    while (m -- ) {
        // 找到第一个峰值点
        int k = n - 2;
        while(a[k] > a[k + 1]) k --;
        //  找到后面最小的数值
        int t = k;
        while(t + 1 < n && a[t + 1] > a[k]) t ++;
        swap(a[t], a[k]);
        reverse(a + k + 1, a + n);
    }
    
    for (int i = 0; i < n; i ++ ) printf("%d ", a[i]);
    return 0;
}