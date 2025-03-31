/*
* @Author: Yanpb
* @Date:   2025-03-27 17:00:35
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-27 17:01:59
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int st[N], a[N], b[N];

int main() {
    int t; cin >> t;
    while(t --) {
        int n, tt = 0;
        cin >> n;
        for (int i = 1; i <= n; i ++) cin >> a[i];
        for (int i = 1; i <= n; i ++) cin >> b[i];

        int pa = 1, pb = 1;
        while(pb <= n) {
            // stack is not empty and b[pb] is the top in the stack
            while(tt && st[tt] == b[pb]) {
                tt --, pb ++;
                continue;
            }
            // a[pa] push in the stack
            if(pa <= n) {
                st[++ tt] = a[pa], pa ++;
            } else {
                break;
            }

        }
        if(pb > n) puts("Yes");
        else puts("No");
    }
   
    return 0;
}