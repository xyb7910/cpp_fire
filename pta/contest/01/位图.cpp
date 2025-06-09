/*
* @Author: Yanpb
* @Date:   2025-05-08 14:31:24
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-05-08 15:54:28
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
// #define x first
// #define y second
using namespace std;
typedef pair<int, int> PII;
const int N = 210;
int n, m;
int map[N][N], dist[N][N];
queue<PII> q;

int main() {
	cin >> n >> m;
	memset(dist, -1, sizeof dist);
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			scanf("%d", &map[i][j]);
			if(map[i][j]) {
				q.push({i, j});
				dist[i][j] = 0;
			} 
		}
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
	while(q.size()) {
		auto t = q.front();
		q.pop();
		int x = t.first, y = t.second;
		for (int i = 0; i < 4; i ++) {
			int a = x + dx[i], b = y + dy[i];
			if(a < 1 || a > n || b < 1 || b > m || dist[a][b] != -1) continue;
			dist[a][b] = dist[x][y] + 1;
			q.push({a, b});
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			printf("%d ", dist[i][j]);
		}
		puts("");
	}
	return 0;
}