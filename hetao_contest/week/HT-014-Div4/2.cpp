#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
LL n, a1, sum;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> a1;
	LL c = a1;
	for (int i = 2; i <= n; i ++) {
		if (c % i == 0) sum += c;
		else {
			c = (c / i + 1) * i; // 计算当前 i 大于 c 的最小倍数
			sum += c;
		}
	}
	cout << sum;
	return 0;
}