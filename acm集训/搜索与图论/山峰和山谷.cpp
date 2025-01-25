/*
* @Author: Yanpb
* @Date:   2025-01-25 12:51:21
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-25 13:46:02
*/
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;
typedef pair<int, int> PII;
const int N = 1e3 + 10, M = N * N;
int h[N][N];
bool st[N][N];
PII q[M];
int n;

void bfs(int sx, int sy, bool& is_higher, bool& is_lower) {
    int hh = 0, tt = 0;
    q[0] = {sx, sy};
    st[sx][sy] = 1;
    
    while(hh <= tt) {
        auto t = q[hh ++];
        
        for (int i = t.x - 1; i <= t.x + 1; i ++)
            for (int j = t.y - 1; j <= t.y + 1; j ++) {
                if(i == t.x && j == t.y) continue;
                if(i < 0 || i >= n || j < 0 || j >= n) continue;
                 
                if(h[i][j] != h[t.x][t.y]) {
                    if(h[i][j] > h[t.x][t.y]) is_higher = 1;
                    else if(h[i][j] < h[t.x][t.y]) is_lower = 1;
                } else if(!st[i][j]) {
                    q[++ tt] = {i, j};
                    st[i][j] = 1;
                }
            }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            cin >> h[i][j];
            
    int peak = 0, valley = 0;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++) {
            if(!st[i][j]) {
                bool is_higher = 0, is_lower = 0;
                bfs(i, j, is_higher, is_lower);
                if(!is_higher) peak ++;
                if(!is_lower) valley ++;
            }
        }
        
    cout << peak << " " << valley;
    return 0;
}