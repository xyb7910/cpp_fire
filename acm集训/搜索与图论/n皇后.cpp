/*
* @Author: Yanpb
* @Date:   2025-08-08 15:15:46
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-08-08 15:51:20
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int n;
char g[N][N];
bool col[N], dg[N], udg[N];

void dfs(int u) {
	if(u == n) {
		for (int i = 0; i < n; i ++) puts(g[i]);
		cout << "\n";
		return ;
	}

	// 判断当前第u行的皇后应该放到第i列
	for (int i = 0; i < n; i ++) {
		if(!col[i] && !dg[u + i] && !udg[n - u + i])
		{
			g[u][i] = 'Q';
			col[i] = dg[u + i] = udg[n - u + i] = 1;
			dfs(u + 1);
			col[i] = dg[u + i] = udg[n - u + i] = 0;
			g[u][i] = '.';
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < n; j ++)
			g[i][j] = '.';
	dfs(0);
	return 0;
}