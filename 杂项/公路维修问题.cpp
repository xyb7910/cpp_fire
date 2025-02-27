/*
* @Author: Yanpb
* @Date:   2025-02-24 20:41:02
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-24 20:47:49
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e4 + 10;
int a[N], b[N];
int n, m;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> a[i];
	int res = a[n - 1] - a[0] + 1;
	for (int i = 1; i < n; i ++) b[i] = a[i] - a[i - 1] - 1;
	sort(b + 1, b + 1 + n, greater<int>());
	for (int i = 0; i < m; i ++) res -= b[i];
	cout << res;
	return 0;
}