/*
* @Author: Yanpb
* @Date:   2025-03-22 12:51:03
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-22 16:56:23
*/
#include <iostream>
using namespace std;

const int N = 110;
int n, m, cnt;
char map[N][N];

void dfs(int x, int y) {
    map[x][y] = '.';  // 将当前有水区域抽干
    
    int dx[8]={1, 1, 1, 0, 0, -1, -1, -1};
    int dy[8]={1, 0, -1, 1, -1, 1, 0, -1};
    for (int i = 0; i < 8; i ++) {
        int tx = x + dx[i], ty = y + dy[i];
        // 检查边界条件
        if (map[tx][ty] == 'W') {
            dfs(tx, ty);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) 
        for (int j = 1; j <= m; j ++)
            cin >> map[i][j];
            
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            if (map[i][j] == 'W') {
                dfs(i, j);
                cnt ++;
            }
    
    cout << cnt;
    return 0;
}