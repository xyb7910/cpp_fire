/*
* @Author: Yanpb
* @Date:   2025-03-07 19:17:50
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-07 19:19:56
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
const int N = 1e6 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, k;
int s[N];

void solved() {
	/* your code */
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		int num; cin >> num;
		s[i] += s[i - 1] + num; 
	}
	int res = 0;
	for (int i = k;  i <= n; i ++) {
		res = max(res, s[i] - s[i - k - 1]);
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}