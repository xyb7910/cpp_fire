/*
* @Author: Hetao
* @Date:   2025-03-06 15:07:16
* @Last Modified by:   Hetao
* @Last Modified time: 2025-03-06 16:30:07
*/
#include <iostream>
#include <cstdio>
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
const int N = 1e6 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m;
i64 w[N], b[N];
int d[N], s[N], t[N];

bool check(int mid) {
	memset(b, 0, sizeof b);
	for (int i = 1; i <= mid; i ++) {
		b[s[i]] += d[i];
		b[t[i] + 1] -= d[i];
	}

	for (int i = 1; i <= n; i ++) {
		b[i] += b[i - 1];
		if(b[i] > w[i]) return false;
	}
	return true;
}

void solved() {
	/* your code */
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) scanf("%d", &w[i]);
	for (int i = 1; i <= m; i ++) scanf("%d%d%d", &d[i], &s[i], &t[i]);

	int l = 0, r = m;
	while(l < r) {
		// 表示天数
		int mid = l + r + 1 >> 1;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}	
	if(r == m) puts("0");
	else printf("-1\n%d", r + 1);
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}