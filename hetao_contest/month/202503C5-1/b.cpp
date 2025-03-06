/*
* @Author: Yanpb
* @Date:   2025-03-06 13:48:58
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-06 14:02:28
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

int n, k, maxv;
int hungry[N], cnt[N];
i64 ans;

void solved() {
	/* your code */
	cin >> n >> k;
	for (int i = 0; i < n; i ++) {
		cin >> hungry[i];
		cnt[hungry[i]] ++;
		maxv = max(maxv, hungry[i]);
	} 

	for (int i = 1; i <= maxv; i ++) {
		i64 res = 0;
		for (int j = i; j <= i + k; j ++) {
			if(cnt[j]) res += j * cnt[j];
		}
		ans = max(ans, res);
	}
	cout << ans;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}