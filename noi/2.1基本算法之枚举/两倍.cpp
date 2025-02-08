/*
* @Author: Yanpb
* @Date:   2025-02-08 17:00:39
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-08 17:06:35
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110;

int n, x, cnt;
int st[N], a[N];

int main() {
    while(cin >> x && x) a[n ++] = x, st[x] = 1;
    sort(a, a + n);
    for (int i = 0; i < n; i ++) 
        if(st[a[i] * 2]) cnt ++;
    cout << cnt;
    return 0;
}