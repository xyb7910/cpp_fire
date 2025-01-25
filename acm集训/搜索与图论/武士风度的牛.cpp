/*
* @Author: Yanpb
* @Date:   2025-01-25 14:31:00
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-25 14:52:11
*/
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second
using namespace std;
/*
八连通分量 日字形
*/
typedef pair<int, int> PII;

const int N = 200, M = N * N;
int n, m, stx, sty;
char g[N][N];
PII q[M];
int dist[N][N];

int bfs(int sx, int sy) {
    int hh = 0, tt = 0;
    memset(dist, -1, sizeof dist);
    int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
    
    q[0] = {sx, sy};
    dist[sx][sy] = 0;
    
    while(hh <= tt) {
        auto t = q[hh ++];
        
        if(g[t.x][t.y] == 'H') {
            return dist[t.x][t.y];
        }
        
        for (int i = 0; i < 8; i ++) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= m) continue;
            if(g[a][b] == '*' || dist[a][b] != -1) continue;
            
            dist[a][b] = dist[t.x][t.y] + 1;
            q[++ tt] = {a, b};
        }
    }
    return -1;
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++) {
            cin >> g[i][j]; 
            if(g[i][j] == 'K') {
                stx = i, sty = j;
            }
        }
        
    cout << bfs(stx, sty);
    return 0;
}