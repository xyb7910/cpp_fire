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
const int N = 110;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int q[N], r[N];

void solved() {
	/* your code */
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> q[i] >> r[i];
	int T;
	cin >> T; 
	while(T --) {
		int t, d;
		cin >> t >> d;
		int s1 = d / q[t] * q[t] + r[t];
		int s2 = (d / q[t] + 1) * q[t] + r[t];
		if(d <= s1) cout << s1 << endl;
		else cout << s2 << endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}