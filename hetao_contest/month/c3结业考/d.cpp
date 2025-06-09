/*
* @Author: Yanpb
* @Date:   2025-05-09 13:04:56
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-05-09 15:02:03
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
typedef priority_queue<int,vector<int>,greater<int>> PIG;
typedef priority_queue<int> PIL; 
const int N = 1e6 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n;
int s[N];

void solved() {
	/* your code */
	cin >> n;
	int c = 0;
	while(n --) {
		int l, r, v; cin >> l >> r >> v;
		s[l] += v, s[r + 1] -= v;
		c = max(c, r);
	}
	int ans = 0;
	for (int i = 1; i <= c; i ++) {
		s[i] += s[i - 1];
		ans = max(ans, s[i]);
	} 
	cout << ans;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}