/*
* @Author: Yanpb
* @Date:   2025-01-19 09:22:08
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-19 09:22:22
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int res[N], b[N], l[N];

int main()
{
    int n, d;
    cin >> n >> d;
    for (int i = 0; i < n; i ++ ) cin >> b[i] >> l[i];
    
    while(d --) {
        for (int i = 0; i < n; i ++ ) {
            l[i] ++;
            res[i] = b[i] * l[i];
        }
        sort(res, res + n);
        cout << res[n - 1] << endl;
    }
    return 0;
}