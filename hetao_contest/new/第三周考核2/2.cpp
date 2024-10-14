#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int n, q;
int h[N], w[N];

bool check(int k) {
	int sum = 0;
	for (int  i = 0; i < n; i ++) {
		sum += (h[i] / k) * (w[i] / k);
	}
	return sum >= q;
}

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i ++) cin >> h[i] >> w[i];
	int l = 1, r = N;
	while(l < r) {
		int mid = l + r + 1 >> 1;
		if(check(mid)) {
			l = mid;
		} else {
			r = mid - 1;
		}
	}
	cout << r << endl;
	return 0;
}