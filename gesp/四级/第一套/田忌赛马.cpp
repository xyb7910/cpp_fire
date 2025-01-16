/*
* @Author: Yanpb
* @Date:   2025-01-13 22:50:13
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-13 23:15:32
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 5e4 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int a[N], b[N];

void solved() {
    /* your code */
	int n; cin >> n;
	for (int i = 0; i < n; i ++) cin >> a[i];
	for (int j = 0; j < n; j ++) cin >> b[j];

	sort(a, a + n), sort(b, b + n);
	int l = 0, r = 0;
	LL ans = 0;
	while(l <= n && r <= n) {
		if(a[l] < b[r]) l ++;
		else {
			ans ++;
			l ++;
			r ++;
		}
	}
	cout << ans;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}