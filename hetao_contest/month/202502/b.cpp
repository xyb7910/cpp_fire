/*
* @Author: Yanpb
* @Date:   2025-02-28 13:03:51
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-28 16:23:30
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
const int N = 1010 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m, r;
bool st[N][N];
int cnt;
void solved() {
	/* your code */
	cin >> n >> m >> r;
	while(m --) {
		int x, y; cin >> x >> y;
		for (int i = max(1, x - r); i <= min(x + r, n); i ++)
			for (int j = max(1, y - r); j <= min(y + r, n); j ++)
				if((i - x) * (i - x) + (j - y) * (j - y) <= (r * r)) {
					st[i][j] = 1;
				}
					
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if(st[i][j]) cnt ++;
		}
	}
	cout << cnt;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}