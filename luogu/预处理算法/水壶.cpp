/*
* @Author: Yanpb
* @Date:   2025-01-03 15:31:19
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-03 15:31:25
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
typedef long long LL;
int s[N];

int main()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i ++) {
        int num; cin >> num;
        s[i] += s[i - 1] + num;
    }
    
    int res = 0;
    for (int i = k; i <= n; i ++) {
        res = max(res, s[i] - s[i - k - 1]);
    }
    cout << res << endl;
    return 0;
}
