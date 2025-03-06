/*
* @Author: Yanpb
* @Date:   2025-03-06 17:21:00
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-06 19:56:29
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

int n, k, mx, my, cnt;
int b[N][N], s[N][N];

void solved() {
	/* your code */
	cin >> n >> k;
	while(n --) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		mx = max(mx, x2), my = max(my, y2);
		b[x1 + 1][y1 + 1] ++;
		b[x2 + 1][y2 + 1] ++;
		b[x1 + 1][y2 + 1] --;
		b[x2 + 1][y1 + 1] --;
	}

	for (int i = 1; i <= mx; i ++) {
		for (int j = 1; j <= my; j ++) {
			b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
			if(b[i][j] == k) cnt ++;
		}
	}
	cout << cnt;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}