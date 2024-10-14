#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
LL a, b, c;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> a >> b >> c;
	if (!(a % c) && !(b % c)) {
		cout  << (a / c) * (b / c) << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}