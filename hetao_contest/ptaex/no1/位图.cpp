/*
* @Author: Yanpb
* @Date:   2025-03-20 20:21:40
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-20 20:46:52
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
const int N = 1e3 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

/*
题目链接：https://www.luogu.com.cn/problem/P2335
*/
int n, m;
int map[N][N];
int dist[N][N];
queue<PII> q;

void bfs() {
	memset(dist, -1, sizeof(dist));
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			if(map[i][j] == 1) {
				q.push({i, j});
				dist[i][j] = 0;
			}
		}

	while(q.size()) {
		auto h = q.front();
		q.pop();
		int x = h.first, y = h.second;
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
			 std::cin >> map[i][j];

	// bfs();

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			std::cout << map[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}