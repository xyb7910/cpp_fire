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
const int N = 1010;
const int MOD = 100003;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int d[N][N]; // 表示当前节点的方案数
bool s[N][N]; // 标记当前位置是否有障碍

void solved() {
	/* your code */
	int n, m;
	cin >> n >> m;
	while(m --) {
		int x, y;
		cin >> x >> y;
		s[x][y] = 1; // 对输入的障碍的位置进行标记
	}

	d[1][1] = 1; // 第一个位置的方案数为1
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			// 如果这个节点是[1, 1] or 这个节点是障碍物，则执行下一次循环
			if((j == 1 && i == 1) || s[i][j]) continue;
			// 下一步的方案数等于从当前节点的上方和从当前节点的左方来之和
			d[i][j] = (d[i - 1][j] + d[i][j - 1]) % MOD;
		}
	}
	cout << d[n][n] << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}