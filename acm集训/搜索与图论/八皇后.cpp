/*
* @Author: Yanpb
* @Date:   2025-08-08 15:31:49
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-08-08 16:12:14
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 30;
int n, res, ans[N];
bool col[N], dg[N], udg[N];
void dfs(int u) {
	if(u > n) {
		res ++;
		if(res <= 3) {
			for (int i = 1; i <= n; i ++) cout << ans[i] << " ";
			cout << endl;
		}
		return ;
	}
	
	for (int i = 1; i <= n; i ++)
	{
		if(!col[i] && !dg[u + i] && !udg[n - u + i])
		{
			col[i] = dg[u + i] = udg[n - u + i] = 1;
			ans[u] = i;
			dfs(u + 1);
			col[i] = dg[u + i] = udg[n - u + i] = 0;
			ans[u] = 0;
		}
	}
}

int main() {
	cin >> n;
	dfs(1);
	cout << res;
	return 0;
}