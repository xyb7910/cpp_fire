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

int n;
int a[N], tr[N];
int G[N], L[N];

int lowbit(int x) {
	return x & -x;
}

void add(int x, int c) {
	for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

LL sum(int x) {
	LL res = 0;
	for (int i = x; i; i -= lowbit(i)) res += tr[i];
	return res;
}

void solved() {
	/* your code */
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	for (int i = 1; i <= n; i ++) {
		int y = a[i];
		G[i] = sum(n) - sum(y);
		L[i] = sum(y - 1);
		add(y, 1);
	}


	memset(tr, 0, sizeof tr);
	LL res1 = 0, res2 = 0;
	for (int i = n; i; i --) {
		int y = a[i];
		res1 += G[i] * (LL)(sum(n) - sum(y));
		res2 += L[i] * (LL)(sum(y - 1));
		add(y, 1);
	}

	cout << res1 << " " << res2 << endl;

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}