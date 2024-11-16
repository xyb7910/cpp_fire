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
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, m;
LL a[N], tr1[N], tr2[N];

int lowbit(int x) {
	return x & -x;
}

void add(LL q[], int x, LL c) {
	for(int i = x; i <= n; i += lowbit(i)) q[i] += c;
}

LL sum(LL q[], int x) {
	LL res = 0;	
	for (int i = x; i; i -=lowbit(i)) res += q[i];
	return res;
}
	
LL presum(int x) {
	return sum(tr1, x) * (x + 1) - sum(tr2, x);
}	

void solved() {
	/* your code */
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];

	// 构建 树状数组
	for (int i = 1; i <= n; i ++) {
		int b = a[i] - a[i - 1];
		add(tr1, i, b);
		add(tr2, i, (LL)i * b);
	}

	while(m --) {
		char op[2];
		int l, r, d;
		cin >> op >> l >> r;		
		if(*op == 'C') {	
			int d;
			cin >> d;
			// tr[l] += d;
			add(tr1, l, d), add(tr2, l, l * d);
			// tr[r + 1] -= d;
			add(tr1, r + 1, -d), add(tr2, r + 1, (r + 1) * -d);
		} else {
			cout << presum(r) - presum(l - 1) << endl;
		}
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}