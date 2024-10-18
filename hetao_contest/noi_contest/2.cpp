#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
LL n, ans;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	while(n --) {
		LL num;
		cin >> num;
		ans += pow(num / 10, num % 10);
	}
	cout << ans << endl;
	return 0;
}