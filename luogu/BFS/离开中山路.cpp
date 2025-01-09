/*
* @Author: Yanpb
* @Date:   2025-01-08 13:52:29
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-08 14:41:44
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
const int N = 1e3 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n;
char map[N][N];
int dist[N][N];
bool st[N][N];
PII q[N];

int bfs(int x1, int y1, int x2, int y2) {
	memset(dist, -1, sizeof(dist));
	int hh = 0, tt = 0;
	q[0] = {x1, y1};
	dist[x1][y1] = 0;

	while(hh <= tt) {
		auto t = q[hh ++];
		if(t.x == x2 && t.y == y2) return dist[x2][y2];
		for (int i = 0; i < 4; i ++) {
			int a = t.x + dx4[i], b = t.y + dy4[i];
			if(a <= 0 || a > n || b <= 0 || b > n) continue;
			if(map[a][b] == '1' || dist[a][b] != -1) continue;
			dist[a][b] = dist[t.x][t.y] + 1;
// 			cout << a << " " << b << endl;
			q[++ tt] = {a, b};
		}
	}
	return -1;
}

void solved() {
    /* your code */
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			cin >> map[i][j];

	int x1, x2, y1, y2; cin >> x1 >> y1 >> x2 >> y2;
	cout << bfs(x1, y1, x2, y2);
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}