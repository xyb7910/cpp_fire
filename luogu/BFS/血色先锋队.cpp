/*
* @Author: Yanpb
* @Date:   2025-01-11 16:25:30
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-11 16:41:16
*/
#include <iostream>
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
const int N = 1e3 + 10, M = 1e6 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

PII q[M];
int dist[N][N];
int n, m, a, b;

void solved() {
	/* your code */
	cin >> n >> m >> a >> b;
	memset(dist, -1, sizeof(dist));
	int hh = 0, tt = 0;
	while(a --) {
		int x, y; cin >> x >> y;
		q[++ tt] = {x, y};
		dist[x][y] = 0;	
	}
	while(hh <= tt) {
		auto h = q[hh ++];

		for (int i = 0; i < 4; i ++) {
			int a = h.first + dx4[i], b = h.second + dy4[i];
			if(a < 1 || a > n || b < 1 || b > m) continue;
			if(dist[a][b] != -1) continue;
			dist[a][b] = dist[h.first][h.second] + 1;
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