#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

int main() {
	int a, b, m, n;
	cin >> a >> b >> m >> n;
	LL ans = a + b;
	for (int i = 3; i <= n; i ++) {
		int c = a + b;
		a = b;
		b = c;
		ans += c;
		if(c >= m) break;
	}
	cout << ans << endl;
	return 0;
}