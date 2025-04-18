/*
* @Author: Yanpb
* @Date:   2025-02-07 10:18:35
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-07 10:19:18
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 40;
int a[N][N];

int n;

int main() {
    cin >> n;
    
    int x = 1, y = n / 2 + 1;
    for (int i = 1; i <= n * n; i ++) {
        a[x][y] = i;
        if(x == 1 && y == n) x ++;
        else if(x == 1) x = n, y ++;
        else if(y == n) x --, y = 1;
        else if(a[x - 1][y + 1]) x ++;
        else x --, y ++;
    }
    
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    
    return 0;
}