/*
* @Author: Yanpb
* @Date:   2025-04-24 20:39:24
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-24 20:50:57
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e6 + 10;
int w[N];
int main() 
{   
    int n; cin >> n;
    int cnt = 0, max_d = -1, max_v = -1, d = 1, sum = 0;
    for (int i = 1; i <= n; i ++) {
        int num; cin >> num;
        sum += num;
        cnt ++;
        if(cnt == (1 << (d - 1)) || i == n) {
            if(max_v < sum) {
                max_d = d;
                max_v = sum;
            }
            cnt = 0;
            w[d] = sum;
            d ++;
            sum = 0;
        }
    }
    cout << max_d;
    return 0;
}