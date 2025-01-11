/*
* @Author: Yanpb
* @Date:   2025-01-11 14:32:27
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-11 16:10:50
*/
/* 多源 BFS */
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e3 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m;
char map[N][N];
int dist[N][N];
queue<PII> q;

void bfs() {
	memset(dist, -1, sizeof(dist));
	// 将所有的 1 的节点入队
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if(map[i][j] == '1') {
				q.push({i, j});
				dist[i][j] = 0;
			}
		}
	}

	while(q.size()) {
		auto h = q.front();
		q.pop();
		int x = h.first, y = h.second;
// 		cout << x << " " << y << endl;
		for (int i = 0; i < 4; i ++) {
			int a = x + dx4[i], b = y + dy4[i];
			if(a < 1 || a > n || b < 1 || b > m) continue;
			if(dist[a][b] != -1) continue;
			dist[a][b] = dist[x][y] + 1;
			q.push({a, b});
		}
	}
}

void solved() {
	/* your code */
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	    for (int j = 1; j <= m; j ++)
	        cin >> map[i][j];
		

	bfs();
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cout << dist[i][j] << " ";
		}
		cout << endl;
	}
		
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}