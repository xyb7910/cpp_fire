/*
* @Author: Yanpb
* @Date:   2025-01-10 20:04:14
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-10 22:21:13
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
const int N = 1e4 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

char map[N][N];
int n, m;
PII q[N];
bool st[N][N];

void solved() {
	/* your code */
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	    for (int j = 1; j <= m; j ++)
	        cin >> map[i][j];
    
    int hh = 0, tt = 0;
	q[0] = {1, 1};
	st[1][1] = 1;

	while(hh <= tt) {
		auto t = q[hh ++];
		if(t.x == n && t.y == m) {
			cout << "Yes";
			return ;
		}

		for (int i = 0; i < 4; i ++) {
			int a = t.x + dx4[i], b = t.y + dy4[i];
			if(map[a][b] == '.' && !st[a][b]) {
				q[++ tt] = {a, b};
				st[a][b] = 1;
			}
			
		}
	}
	cout << "No";
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}