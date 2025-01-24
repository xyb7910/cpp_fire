/*
* @Author: Yanpb
* @Date:   2025-01-24 22:02:30
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-24 22:03:02
*/
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;

/*
每次 bfs 可以求出一个连通块的大小 area
*/
const int N = 55, M = N * N;

typedef pair<int, int> PII;
int n, m;
int g[N][N];
bool st[N][N];
PII q[M];

int bfs(int sx, int sy) {
    int hh = 0, tt = 0;
    // 首元素入队
    q[0] = {sx, sy};
    st[sx][sy] = 1;
    int area = 0;
    int dx[4] = {1, -1, 0, 0}, dy[4] = {0 ,0, -1, 1};
    
    while(hh <= tt) {
        // 出队
        auto t = q[hh ++];
        area ++;
        
        for (int i = 0; i < 4; i ++) {
            int a = t.x + dx[i], b = t.y + dy[i];
            if(a < 0 || a >= n || b < 0 || b >= m) continue;
            if(st[a][b] || g[t.x][t.y] >> i & 1) continue;
            
            q[++ tt] = {a, b};
            st[a][b] = 1;
        }    
    }
    return area;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
        
    int area = 0, cnt = 0; // 分别表示最大的面积 和 房间的数量
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++) {
            if(!st[i][j]) {
                area = max(area, bfs(i, j));
                cnt ++;
            }
        }
    cout << cnt << endl << area;
    return 0;
}