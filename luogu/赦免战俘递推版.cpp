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
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

// 因为 n <= 10, 所以最大值为 2^10=1024
// 每一个数字等于它正上方 + 右上方 对2取余
int n;
int a[(1 << 10) + 10][(1 << 10) + 10];
void solved() {
	/* your code */
	cin >> n;
	n = 1 << n;
	for (int i = 1; i <= n; i ++) a[i][n] = 1;

	for (int i = 2; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			a[i][j] = (a[i - 1][j] + a[i - 1][j + 1]) % 2;
		}
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
		
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}