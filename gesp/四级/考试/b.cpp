/*
* @Author: Yanpb
* @Date:   2025-01-24 13:19:25
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-24 14:06:10
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

int ans[N], cnt = 1;

void solved() {
	/* your code */
	int n; cin >> n;
	// vector<int> ans(n);
	ans[1] = 1;
	for (int i = 2; i <= n; i ++) {
		int res = ans[i - 1] - i, res1 = ans[i - 1] + i;
		bool  f = 0;
		for (int j = 1; j <= cnt; j ++) {
			if(ans[j] == res) f = true;
		}
		if(!f && res > 0) ans[i] = res;
		// if(ans.find(res) == ans.end() && res > 0) ans[i] = res;
		else ans[i] = res1;
		cnt ++;
	}
	sort(ans + 1, ans + n + 1);
	// sort(ans.begin(), ans.end() + 1);
	for (int i = 1; i <= n; i ++) cout << ans[i] << " ";
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}