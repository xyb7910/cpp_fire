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
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e3 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m;
int dp[N][N];
bool st[N][N];
const int MOD = 100003;
void solved() {
	/* your code */
	cin >> n >> m;
	while(m --) {
		int x, y;
		cin >> x >> y;
		st[x][y] = 1;
	}

	// 递推型的 DP问题
	// 初始条件
	dp[1][1] = 1;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if((i == 1 && j == 1) || st[i][j]) continue;
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % MOD;
		}
	}
	cout << dp[n][n] << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}