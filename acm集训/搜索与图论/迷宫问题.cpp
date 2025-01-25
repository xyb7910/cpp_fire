/*
* @Author: Yanpb
* @Date:   2025-01-25 14:04:56
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-25 14:30:22
*/
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;
/*
使用一个数组用来存储当前节点 是由哪一个节点扩展过来的。
之后逆着输出就可以了。
*/
typedef pair<int, int> PII;
const int N = 1e3 + 10, M = N * N;

int n;
int g[N][N];
PII route[N][N];
PII q[M];

void bfs(int sx, int sy) {
    int hh = 0, tt = 0;
    memset(route, -1, sizeof route);
    q[0] = {sx, sy};
    route[sx][sy] = {0, 0};
    
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, -1, 1};
    while(hh <= tt) {
        auto t = q[hh ++];
        
        for (int i = 0; i < 4; i ++) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if(a < 0 ||a >= n || b < 0 || b >= n) continue;
            if(g[a][b] || route[a][b].x != -1) continue;
            
            route[a][b] = t;
            q[++ tt] = {a, b};
        }
        
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < n; j ++)
            cin >> g[i][j];
    
    // 倒着进行宽搜
    bfs(n - 1, n - 1);
    PII end(0, 0);
    
    while(1) {
        cout << end.x << " " << end.y << endl;
        if(end.x == n - 1 && end.y == n - 1) break;
        end = route[end.x][end.y];
    }
    return 0;
}