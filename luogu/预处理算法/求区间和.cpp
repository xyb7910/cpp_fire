/*
* @Author: Yanpb
* @Date:   2025-01-03 15:29:58
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-03 15:31:05
*/
#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;
const int N = 1e5 + 10;
int s[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) {
        int num; cin >> num;
        s[i] += s[i - 1] + num;
    }
    int q; cin >> q;
    while (q -- ) {
        int l, r; cin >> l >> r;
        cout << s[r] - s[l - 1] << endl;
    }
    return 0;
}