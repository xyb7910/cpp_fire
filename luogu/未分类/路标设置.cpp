#include <iostream>
using namespace std;

const int N = 1e7 + 10;

int len, n, k;
int arr[N];

bool check(int x) {
	int prev = arr[1];
	int cnt = 0;
	if (!x) {
		return 1;
	}
	for (int i = 2; i <= n;) {
		int d = arr[i] - prev;
		if (d > x) {
			prev += x;
			cnt++;
		} else {
			prev = arr[i];
			i++;
		}
	}
	return cnt > k;
}

int main() {
	cin >> len >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int l = 0, r = len;
	while (l <= r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	cout << l << endl;
	return 0;
}