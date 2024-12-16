#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 110;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int t[N], w[N];

void solved() {
    /* your code */
    int n; cin >> n;
    for (int i = 1; i <= n; i ++) cin >> t[i] >> w[i];
    int res = 0;
	for (int i = 1; i < n; i ++) {
		res += w[i];
		int d = t[i + 1] - t[i];
		if(d > res) {
			res = 0;
		} else {
			res -= d;
		}
	}

	cout << res + w[n] << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}