/*
* @Author: Yanpb
* @Date:   2025-01-03 21:37:46
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-04 15:12:22
*/
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
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int s[N];
int a[7], b[7];

void solved() {
	/* your code */
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> s[i];
		s[i] = (s[i - 1] + s[i]) % 7;
	}

	for (int i = n; i >= 1; i --) a[s[i]] = i;
	a[0] = 0;
	for (int i = 1; i <= n; i ++) b[s[i]] = i;

	int res = -1;
	for (int i = 0; i <= 6; i ++) {
		res = max(res, b[i] - a[i]);
	}
	
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}