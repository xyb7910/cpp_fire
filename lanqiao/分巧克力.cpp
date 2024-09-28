#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 1e5;
int n, k;
int h[N], w[N];
// 二分正方形的边长
bool check(int a) {
	LL sum = 0;
	for (int i = 0; i < n; i ++) {
		sum += (h[i] / a) * (w[i] / a);
	}
	return sum >= k;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i ++) cin >> h[i] >> w[i];
	int l = 1, r = N;
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		};
	}
	cout << r << endl;
	return 0;
}