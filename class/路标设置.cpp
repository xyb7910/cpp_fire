#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int a[N];
LL m, n, k;

bool check(LL x) {
	LL res = 0;
	for (int i = 1; i < n; i ++) {
		LL d = a[i] - a[i - 1];
		if (d > x) {
			res += d / x;
			if (d % x == 0) res --;
		}
		if (res > k) return false;
	}
	return res <= k;
}


int main() {
	std::cin >> m >> n >> k;
	for (int i = 0; i < n; i ++) std::cin >> a[i];
	sort(a, a + n);
	LL l = 0, r = m;
	while(l < r) {
		LL mid = l + r >> 1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	std::cout << l << std::endl;
	return 0;
}