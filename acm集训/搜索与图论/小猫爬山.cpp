/*
* @Author: Yanpb
* @Date:   2025-08-09 16:52:31
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-08-09 18:22:43
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n, m, ans = N;
int w[N], sum[N];

void dfs(int u, int k) {
	// 最优性剪枝
	if(k >= ans) return ;
	if(u == n) {
		ans = k;
		return ;
	}

	// 第k辆车可以载第u只猫
	for (int i = 0; i < k; i ++)
	{
		// 可行性剪枝
		if(sum[i] + w[u] <= m)
		{
			sum[i] += w[u];
			dfs(u + 1, k);
			sum[i] -= w[u];
		}				
	}
	// 第k辆车不可以载第u只猫,新增加一辆车
	sum[k] += w[u];
	dfs(u + 1, k + 1);
	sum[k] -= w[u];
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> w[i];
	// 为保证最优性，搜索树最低
	sort(w, w + n, greater<int>());
	dfs(0, 0);
	cout << ans;
	return 0;
}