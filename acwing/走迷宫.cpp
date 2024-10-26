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
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 110;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m;
int map[N][N];
int dist[N][N];

// 输出最少的移动次数
int bfs() {
	queue<PII> q;

	memset(dist, -1, sizeof dist);
	dist[0][0] = 0;
	q.push({0, 0});

	while(!q.empty()) {
		auto t = q.front();
		q.pop();

		for (int i = 0; i < 4; i ++) {
			int a = t.first + dx4[i], b = t.second + dy4[i];
			if(a >= 0 && a < n && b >= 0 && b < m && map[a][b] == 0 && dist[a][b] == -1) {
				dist[a][b] = dist[t.first][t.second] + 1;
				q.push({a, b});
			}
		}
	}
	return dist[n - 1][m - 1];
}

void solved() {
	/* your code */
	std::cin >> n >> m;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			std::cin >> map[i][j];
		}
	}

	int d = bfs();
	std::cout << d << std::endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}