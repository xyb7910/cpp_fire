#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e6 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int primes[N], s[N];
bool st[N];
int cnt;

void solved() {
	/* your code */
	int n, m; cin >> n >> m;
	for (int i = 2; i <= m; i  ++) {
		s[i] = s[i - 1];
		if(!st[i]) {
			primes[cnt ++] = i;
			s[i] = cnt;
		}
		for (int j = 0; primes[j] * i <= m; j ++) {
			st[primes[j] * i] = 1;
			if(i % primes[j] == 0) break;
		}
	}
	for (int i = 1; i <= n; i ++) {
		int l, r; cin >> l >> r;
		if(l < 1 || r > m) cout << "Crossing the line" << endl;
		else cout << s[r] - s[l - 1] <<  endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}