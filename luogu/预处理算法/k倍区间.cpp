/*
* @Author: Yanpb
* @Date:   2025-01-04 15:14:40
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-04 16:31:31
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
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

i64 res[N] = {1};
i64 ans;
int rem;

void solved() {
	/* your code */
	// 倍数意味着与 0 同余
	int n, k; cin >> n >> k;
	for (int i = 0; i < n; i ++) {
		int num; cin >> num;
		rem += num;
		res[rem % k] ++;
		rem %= k;
	}

	for (int i = 0; i < k; i ++) ans += res[i] * (res[i] - 1) / 2;
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}