/*
* @Author: Yanpb
* @Date:   2025-01-11 23:15:55
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-12 10:08:51
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e2 + 10, M = N * N;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
// 洪水灌溉做法

int n;
int map[N][N];
bool st[N][N];
PII q[M];

void bfs(int x, int y) {
	int hh = 0, tt = 0;
	q[0] = {x, y};
	st[x][y] = 1;


	while(hh <= tt) {
		auto h = q[hh ++];

		for (int i = 0; i < 4; i ++) {
			int a = h.first + dx4[i], b = h.second + dy4[i];
			if(a < 0 || a > n + 1 || b < 0 || b > n + 1) continue;
			if(st[a][b] || map[a][b]) continue;

			q[++ tt] = {a, b};
			st[a][b] = 1;
		}
	}
}

void solved() {
    /* your code */
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			cin >> map[i][j];

	bfs(1, 1);

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if(map[i][j] == 0 && !st[i][j]) map[i][j] = 2;
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}