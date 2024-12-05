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
const int N = 510;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int num[N][N], f[N][N];
int n;
void solved() {
	/* your code */
	std::cin >> n;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= i; j ++) {
			std::cin >> num[i][j];
		}
	}

	for (int i = 1; i <= n; i ++) f[n][i] = num[n][i];

	for (int i = n - 1; i >= 1; i --) {
		for (int j = 1; j <= i; j ++) {
			f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + num[i][j];
		}
	}
	std::cout << f[1][1] << std::endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}