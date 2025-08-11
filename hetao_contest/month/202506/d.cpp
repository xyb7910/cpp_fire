/*
* @Author: Yanpb
* @Date:   2025-06-30 12:19:11
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-06-30 15:45:08
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n, m, sx, sy, ex, ey, w = 6;
struct Pos
{
	int x; int y; int w;
	Pos(int cow, int col, int value) {
		x = cow, y = col, w = value;
	}
};
int c[N][N], dist[N][N];
bool inmap(int x, int y) {
	return x >= 1 && x <= n && y >= 1 && y <= m;
}
void bfs() {
	queue<Pos> q;
	memset(dist, -1, sizeof dist);
	q.push(Pos(sx, sy, w));
	dist[sx][sy] = 0;
	int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
	while(q.size()) {
		auto h = q.front();
		q.pop();
		if(h.w <= 0) return ;
		if(c[h.x][h.y] == 4) h.w = 6; 	
		for (int i = 0; i < 4; i ++) {
			int a = h.x + dir[i][0], b = h.y + dir[i][1];
			if(inmap(a, b) && c[a][b] != 0 && dist[a][b] == -1) {
				int c = h.w - 1;
				if(c > 0) {
					q.push({a, b, c});
				 	dist[a][b] = dist[h.x][h.y] + 1;
				}
			}
		}
	}
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			cin >> c[i][j];
			if(c[i][j] == 2) sx = i, sy = j;
			if(c[i][j] == 3) ex = i, ey = j;
		}
	
	bfs();
	cout << dist[ex][ey];	
	return 0;
}