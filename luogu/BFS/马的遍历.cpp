/*
* @Author: Yanpb
* @Date:   2025-01-11 16:14:22
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-11 16:23:08
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e3 + 10, M = 1e6 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m, a, b;
int dist[N][N];
PII q[M];

void solved() {
	/* your code */
	cin >> n >> m >> a >>  b;
	memset(dist, -1, sizeof(dist));
	int hh = 0, tt = 0;
	q[0] = {a, b};
	dist[a][b] = 0;

	while(hh <= tt) {
		auto h = q[hh ++];

		for (int i = 0; i < 8; i ++) {
			int a = h.x + dxr[i], b = h.y + dyr[i];
			if(a < 1 || a > n || b < 1 || b > m) continue;
			if(dist[a][b] != -1) continue;
			dist[a][b] = dist[h.x][h.y] + 1;
			q[++ tt] = {a, b};
		}
	}

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