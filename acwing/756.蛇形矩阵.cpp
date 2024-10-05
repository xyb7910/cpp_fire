#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int res[N][N];
// 右下左上
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};

int main() {
	cin >> n >> m;
	int d = 0;
	for (int x = 0, y = 0, k = 1; k <= n * m; k ++) {
		res[x][y] = k;
		int a = x + dx[d], b = y + dy[d];
		if(a < 0 || a >= n || b < 0 || b >= m || res[a][b]) {
			d = (d + 1) % 4;
			a = x + dx[d], b = y + dy[d];
		}
		x = a, y = b;
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++)
			cout << res[i][j] << " ";
		cout << endl;
	}
	return 0;
}