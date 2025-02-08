/*
* @Author: Yanpb
* @Date:   2025-02-08 17:09:16
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-08 18:08:01
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int n;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i ++)
        for (int j = i; j <= n; j ++)
            for (int k = j; k <= n; k ++) {
                int a = i + j + k;
                if(int(pow(i, 3)) + int(pow(j, 3)) + int(pow(k, 3)) == int(pow(a, 3)))
                    printf("Cube = %d, Triple = (%d,%d,%d)\n", a, i, j, k);
            }
    return 0;
}