/*
* @Author: Yanpb
* @Date:   2025-01-03 15:02:59
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-03 15:21:36
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

int a[N][N], s[N][N];
void solved() {
	/* your code */
	int n, m, c; cin >> n >> m >> c;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			cin >> a[i][j];
		}

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= m; j ++) {
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
		}
	int res = -0x3f3f3f3f, x = 0, y = 0;	
	for (int i = c; i <= n; i ++) 
		for (int j = c; j <= m; j ++) {
			int start_x = i - c + 1, start_y = j - c + 1; 
			int t = s[i][j] - s[i - c][j] - s[i][j - c] + s[i - c][j - c];
			if(t > res) {
				x = start_x, y = start_y;
				res = t;
			}
		}
	cout << x << " " << y << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}