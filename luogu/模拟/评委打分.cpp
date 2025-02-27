/*
* @Author: Yanpb
* @Date:   2025-02-24 16:15:34
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-24 16:15:40
*/
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int n;
int main() {
    cin >> n;
    int minv = 101, maxv = -1; 
    double sum = 0;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        minv = min(minv, x), maxv = max(maxv, x);
        sum += x;
        if(i > 2) {
            sum -= (maxv + minv);
            printf("%.2lf\n", sum / (i - 2));
            sum += (maxv + minv);
        }
    }
    return 0;
}