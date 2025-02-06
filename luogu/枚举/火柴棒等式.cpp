/*
* @Author: Yanpb
* @Date:   2025-02-06 10:21:10
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-06 10:21:19
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int match[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int n;

int get(int x) {
    if(x < 10) return match[x];
    return get(x / 10) + match[x % 10];
}

int main() {
    cin >> n;
    int res = 0;
    for (int i = 0; i < 1000; i ++)
        for (int j = 0; j < 1000; j ++) {
            if(get(i) + get(j) + get(i + j) + 4 == n) res ++;
        }
    cout << res;
    return 0;
}