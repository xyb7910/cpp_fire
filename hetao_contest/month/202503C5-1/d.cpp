/*
* @Author: Yanpb
* @Date:   2025-03-06 14:12:16
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-06 14:34:51
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
const int N = 1e5 + 10, MOD = 9;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int digit_sum(i64 x) {
	i64 sum = 0;
	while(x) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}

void solved() {
	/* your code */
	i64 l, r; cin >> l >> r;
	i64 len = r - l + 1;
	i64 full = len / 9;
	i64 res = 0;
	for (i64 i = l + full * 9; i <= r; i ++) {
		res += digit_sum(i);
		res %= 9;
	}
	cout << res % 9 << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; cin >> t; while(t --) solved();
    return 0;
}