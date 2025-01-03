/*
* @Author: Yanpb
* @Date:   2025-01-03 21:20:37
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-03 22:26:41
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
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e6 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

LL s[N];

void solved() {
	/* your code */
	LL n, k;
	cin >> n >> k;
	for (int i = 1; i <= n - 1; i ++) {
		LL num; cin >> num;
		s[i] += s[i - 1] + num;
	}
	LL res = 0;
	for (int i = k; i <= n - 1; i ++) {
		res = max(res, s[i] - s[i - k]);
	}
	cout << s[n - 1] - res << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}