/*
* @Author: Yanpb
* @Date:   2025-04-07 12:50:32
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-07 15:39:54
*/
/*
* @Author: Yanpb
* @Date:   2025-04-07 12:50:20
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-07 13:54:10
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// #define x first
// #define y second

using namespace std;
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 20 + 10;
int dx4[2] = {1, 0}, dy4[2] = {0, 1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int bx, by, hx, hy;
int map[N][N], vis[N][N];
i64 cnt;

void dfs(int x, int y) {
	if(x == bx && y == by) {
		cnt ++;
		return ;
	}

	vis[x][y] = 1;

	for (int i = 0; i < 2; i ++) {
		int a = x + dx4[i], b = y + dy4[i];
		if(a >= 0 && a <= bx && b >= 0 && b <= by 
			&& !vis[a][b] && !map[a][b]) {
			dfs(a, b);
		}
	}
	vis[x][y] = 0;
}

void solved() {
	/* your code */
	cin >> bx >> by >> hx >> hy;
	map[hx][hy] = 1;
	for (int i = 0; i < 8; i ++)  {
		int a = hx + dxr[i], b = hy + dyr[i];
		map[a][b] = 1;
	}
	dfs(0, 0);
	cout << cnt;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}