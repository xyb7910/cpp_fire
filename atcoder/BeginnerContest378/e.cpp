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
const int N = 2e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m;
int a[N], s[N];

struct BIT{
	#define lowbit(x) ((x) & (-(x)))
	int tree[N];

	void add(int p, int x) {
		++ p;
		while(p < N) {
			tree[p] += x;
			p += lowbit(p);
		}
	}

	int query(int p) {
		++ p;
		if(p <= 0) return 0;

		int res = 0;
		while(p) {
			res += tree[p];
			p -= lowbit(p);
		}
		return res;
	}
}bit;


void solved() {
	/* your code */
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) s[i] = (s[i - 1] + a[i]) % m;

	LL ans = 0;
	for (int r = 1; r <= n; r ++) ans += s[r] * r * 1LL;
	for (int l = 1; l <= n; l ++) ans -= s[l - 1] * (n - l + 1) * 1LL;

	LL cnt = 0;
	for (int i = 1; i <= n; i ++) {
		cnt += i - 1 - bit.query(s[i]);
		bit.add(s[i], 1);
	}
	ans += cnt * m * 1LL;						
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}