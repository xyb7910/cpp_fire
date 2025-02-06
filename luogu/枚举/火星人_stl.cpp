/*
* @Author: Yanpb
* @Date:   2025-02-06 10:20:34
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-06 10:20:51
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
    while (m -- ) next_permutation(a, a + n);
    for (int i = 0; i < n; i ++ ) printf("%d ", a[i]);
    return 0;
}