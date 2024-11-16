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

int n;
int h[N], tr[N], ans[N];


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
	for (int i = 2; i <= n; i ++) cin >> h[i];

	for (int i = 1; i <= n; i ++) add(i, 1);
	
	for (int i = n; i; i --) {
		int k = h[i] + 1;	
		int l = 1, r = n;
		while(l < r) {
			int mid = l + r >> 1;
			if(sum(mid) >= k) r = mid;
			else l = mid + 1;
		}
		ans[i] = r;
		add(r, - 1);
	}

	for (int i = 1; i <= n; i ++) cout << ans[i] << endl;

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}
