/*
* @Author: Yanpb
* @Date:   2025-05-08 16:31:32
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-05-08 16:43:28
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
/*
可以看作是两个人同时从（1， 1）出发，这样就把dp想成四维
*/
const int N = 20;
int num[N][N], dp[N][N][N][N];

int main() {
	int n; cin >> n;
	int x, y, c;
	while(cin >> x >> y >> c) {
		if(!x && !y && !c) break;
		num[x][y] = c;
	}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			for (int r = 1; r <= n; r ++)
				for (int c = 1; c <= n; c ++) {
					int tmp = dp[i - 1][j][r - 1][c];
					tmp = max(tmp, dp[i - 1][j][r][c - 1]);
					tmp = max(tmp, dp[i][j - 1][r - 1][c]);
					tmp = max(tmp, dp[i][j - 1][r][c - 1]);
					dp[i][j][r][c] = tmp + num[i][j] + num[r][c];
					if(i == r && j == c) 
						dp[i][j][r][c] -= num[i][j];

				}
	cout << dp[n][n][n][n];
	return 0;
}