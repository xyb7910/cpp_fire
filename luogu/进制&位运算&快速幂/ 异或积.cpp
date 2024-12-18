#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned uint;

const int MAXN = 1e5 + 10;

int t, n, k;

uint a[MAXN];

int main() {
	for (scanf("%d", &t); t--;) {
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++) scanf("%u", &a[i]);
		for (int p = 0, x, y, z; p < 32; p++) {
			x = y = 0;
			for (int i = 1; i <= n; i++) a[i] >> p & 1 ? ++x : ++y;
			if (n & 1) for (int i = 1; i <= n; i++) a[i] ^= (x & 1) << p;
			else if (x & 1) for (int i = 1; i <= n; i++) a[i] ^= (k & 1) << p;
		}
		for (int i = 1; i <= n; i++) printf("%u ", a[i]); puts("");
	}
}