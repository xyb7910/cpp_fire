/*
* @Author: Yanpb
* @Date:   2025-01-12 22:59:08
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-12 23:18:55
*/
// 多源最短模型
// 1. 将所有起点入队（感染源）
// 2. distance 数组 输出 dist[x][y]

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e3 + 10, M = N * N;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// 手写队列
PII q[M];
int dist[N][N];
int n, m, a, b;

void solved() {
    /* your code */
	cin >> n >> m >> a >> b;
	memset(dist, -1, sizeof dist); // 按字节
	int hh = 0, tt = 0;

	// 先把所有病毒入队
	while(a --) {
		int x, y; cin >> x >> y;
		q[++ tt] = {x, y};
		dist[x][y] = 0;
	}

	// BFS
	while(hh <= tt) {
		auto t = q[hh ++];

		for (int i = 0; i < 4; i ++) {
			int a = t.first + dx4[i], b = t.second + dy4[i];
			if(a < 1 || a > n || b < 1 || b > n) continue;
			if(dist[a][b] != -1) continue;
			dist[a][b] = dist[t.first][t.second] + 1;
			q[++ tt] = {a, b};
		}
	}

	while(b --) {
		int x, y; cin >> x >> y;
		cout << dist[x][y] << endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}