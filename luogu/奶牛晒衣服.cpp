#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

const int N= 5e5 + 10;
int n, a, b;
int w[N];

// 二分的是时间
bool check(int k) {
	int sum = 0;
	for (int i = 0; i < n; i ++) {
		if(w[i] <= a * k) continue;
		else {
			int temp = w[i] - a * k;
			sum += ceil(1.0 * temp / b);
			if (sum > k) return false;
		}
	}
	return sum <= k;
}

int main()
{
	cin >> n  >> a >> b;
	for (int i = 0; i < n; i ++)  cin >> w[i];
	int l = 1, r = N, ans = -1;
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
