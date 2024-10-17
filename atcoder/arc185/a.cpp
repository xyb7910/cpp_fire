#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	int T;
	cin >> T;
	while(T -- ) {
		int n, m;
		cin >> n >> m;
		LL x = 1LL * n * (n + 1) % m;
		if (1 <= x && x <= n) {
			puts("Bob");
		} else {
			puts("Alice");
		}
	}
	return 0;
}