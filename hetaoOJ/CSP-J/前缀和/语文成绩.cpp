/*
* @Author: Yanpb
* @Date:   2025-04-26 14:45:53
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-26 14:51:17
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5e5 + 10;
int d[N];

int main() {
	int n, p; cin >> n >> p;
	for (int i = 1; i <= n; i ++) {
		cin >> d[i];
		d[i] -= d[i - 1];
	}
	while(p --) {
		int x, y, z; cin >> x >> y >> z;
		d[x] += z, d[y + 1] -= z;
	}
	int res = 0x3f3f3f3f;
	for (int i = 1; i <= n; i ++) {
		d[i] += d[i - 1];
		res = min(res, d[i]);
	}
	cout << res;
	return 0;
}