#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int n, m;
int p[N];

bool check(int k) {
	int sum = 1;
	int start = p[0];
	for (int i = 1; i < n; i ++) {
		if(p[i] - start >= k) {
			sum ++;
			start = p[i];
		}
		if(sum >= m) return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int  i = 0; i < n; i++) cin >> p[i];
	sort(p, p + n);
	int l = 1, r = 1e9 + 10;
	while(l <= r) {
		int mid = l + r >> 1;
		if(check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << r << endl;
	return 0;
}