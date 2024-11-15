#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 400;
int sum[N];
int main() {
	int a, b, m, n;
	cin >> a >> b >> m >> n;
	sum[1] = a, sum[2] = b;
	for (int i = 3; i <= n; i ++) {
		int res = sum[i - 1] + sum[i - 2];
		if(res > m) {
			sum[i] = 0;
			break;
		} else {
			sum[i] = res;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) ans += sum[i];
	cout << ans << endl;
	return 0;
}