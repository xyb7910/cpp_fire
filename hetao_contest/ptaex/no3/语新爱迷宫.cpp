/*
* @Author: Yanpb
* @Date:   2025-04-07 12:51:45
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-07 13:05:44
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 20;
int map[N][N], vis[N][N];
int n, m, t, cnt;
int start_x, start_y, end_x, end_y;

void dfs(int x, int y) {
	if(x == end_x && y == end_y) {
		cnt ++;
		return ;
	}

	vis[x][y] = 1;
	int dx[4] = {0, 0, -1, 1}, dy[4] = {-1, 1, 0, 0};

	for (int i = 0; i < 4; i ++) {
		int a = x + dx[i], b = y + dy[i];
		if(a >= 1 && a <= n && b >= 1 && b <= m &&
			!map[a][b] && !vis[a][b]) {
			dfs(a, b);
		}
	}
	vis[x][y] = 0;
}

int main() {
	cin >> n >> m >> t;
	cin >> start_x >> start_y >> end_x >> end_y;
	while(t --) {
		int x, y; cin >> x >> y;
		map[x][y] = 1;
	}
	dfs(start_x, start_y);
	cout << cnt;
	return 0;
}