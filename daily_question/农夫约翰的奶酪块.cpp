#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, q, res;
int front[N][N], side[N][N], top[N][N];

int main() {
    cin >> n >> q;
    while(q --) {
        int x, y, z;
        cin >> x >> y >> z;
        if(++ front[x][y] >= n) res ++;
        if(++ side[y][z] >= n) res ++;
        if(++ top[x][z] >= n) res ++;
        cout << res << endl;
    }
    return 0;
}