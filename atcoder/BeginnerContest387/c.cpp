/*
* @Author: Yanpb
* @Date:   2025-01-17 18:53:06
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-17 21:40:31
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


char g[N][N];
int dist[N][N];
pair<pair<int, int>, bool> q[N * N];
int s_x, s_y, e_x, e_y;

void solved() {
	/* your code */
	int h, w; cin >> h >> w;
	memset(dist, -1, sizeof dist);
	// 先输入
	for (int i = 1;i <= h; i ++)
		for (int j = 1; j <= w; j ++) {
			cin >> g[i][j];
			if(g[i][j] == 'S') {
				s_x = i, s_y = j;
			}
			if(g[i][j] == 'G') {
				e_x = i, e_y = j;
			} 
		}

	int hh = 0, tt = 0;
	q[0] = {{s_x, s_y}, 1}; // 水平
	q[1] = {{s_x, s_y}, 0}; // 
	dist[s_x][s_y] = 1;

	while(hh <= tt) {
		auto t = q[hh ++];
		if(t.x.x == e_x && t.x.y == e_y) {
			cout << dist[t.x.x][t.x.y] << endl;
			return ;
		}
		for (int delta = -1; delta <= 1; delta += 2) {
			if(t.y == )
			if(a < 1 || a > h || b < 1 || b > w) continue;
			if(dist[a][b] != -1 || g[a][b] == '#') continue;
			dist[a][b] = dist[t.x][t.y] + 1;
			q[++ tt] = {a, b};
		}
	}

}


int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}