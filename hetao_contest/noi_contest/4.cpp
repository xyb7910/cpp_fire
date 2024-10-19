#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;

bool check(LL n) {
	// n = abs(n);
	if(n > 4 && n % 4 == 0 || n & 1 == 1) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	LL n;
	cin >> n;
	while(n --) {
		int l, r;
		cin >> l >> r;
		int cnt = 0;
		for (int i = l; i <= r; i ++) {
			if(check(i)) cnt ++;
		}
		cout << cnt << endl;
	}
	return 0;
}