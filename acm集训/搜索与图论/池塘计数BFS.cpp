/*
* @Author: Yanpb
* @Date:   2025-01-24 21:17:11
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-24 21:17:16
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>

#define x first
#define y second

using namespace std;
/*这道题目是一个八联通问题*/
const int N = 1e3 + 10, M = N * N;

typedef pair<int, int> PII;
int n, m;
char g[N][N];
bool st[N][N];
PII q[M];


void bfs(int sx, int sy) {
    int tt = 0, hh = 0;
    // 将第一个元素入队
    q[0] = {sx, sy};
    st[sx][sy] = 1;
    
    while(hh <= tt) {
        // 队列不为空，取出队头进行扩展
        auto t = q[hh ++];
        // 八联通分量 遍历技巧 使用双重循环
        for (int i = t.x - 1; i <= t.x + 1; i ++)
            for (int j = t.y - 1; j <= t.y + 1; j ++) {
                // 跳过自身 {x, y}
                if(i == t.x && j == t.y) continue;
                if(i < 0 || i >= n || j < 0 || j >= m) continue;
                if(st[i][j] || g[i][j] == '.') continue;
                
                q[++ tt] = {i, j};
                st[i][j] = 1;
            }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++) {
            cin >> g[i][j];
        }
        
    int cnt = 0;    
    for (int i = 0; i < n; i ++)
        for (int j = 0; j < m; j ++) {
            if(!st[i][j] && g[i][j] == 'W') {
                bfs(i, j);
                cnt ++;
            }
        }
    cout << cnt;
    return 0;
}