/*
* @Author: Yanpb
* @Date:   2025-05-04 15:35:28
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-05-04 15:40:27
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
typedef priority_queue<int,vector<int>,greater<int>> PIG;
typedef priority_queue<int> PIL; 
const int N = 1e3 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m;
int num[N][N];

void solved() {
	/* your code */
	cin >> n >> m;
	int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
	for (int x = 0, y = 0, k = 1, d = 0; k <= n * m; k ++) {
		num[x][y] = k;
		int a = x + dx[d], b = y + dy[d];
		if(a < 0 || a >= n || b < 0 || b >= m || num[a][b]) {
			d = (d + 1) % 4;
			a = x + dx[d], b = y + dy[d];
		}
		x = a, y = b;
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cout << num[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}