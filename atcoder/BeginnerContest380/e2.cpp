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
const int N = 5e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, q;
int p[N], color[N], cnt[N], ans[N];

int _find(int x) {
	return p[x] != x ? p[x] = _find(p[x]) : p[x];
}

void _union(int a, int b) {
	a = _find(a), b = _find(b);
	if(a > b) swap(a, b);
	p[b] = a, cnt[a] += cnt[b];
}

void solved() {
	/* your code */
	cin >> n >> q;
	for (int i = 1; i <= n; i ++) {
		p[i] = i;
		cnt[i] = 1;
		color[i] = i;
		ans[i] = 1;
	}

	while(q --) {
		int op;
		cin >> op;
		if(op == 1) {
			int x, c;
			cin >> x >> c; // 将x染成c
			x = _find(x);
			ans[color[x]] -= cnt[x];
			ans[c] += cnt[x];
			color[x] = c;
			if(color[_find(x + cnt[x])] == c) _union(x, x + cnt[x]);
			if(color[_find(x - 1)] == c) _union(x - 1, x);
		} else {
			int c;
			cin >> c;
			cout << ans[c] << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}