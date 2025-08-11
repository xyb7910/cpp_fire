/*
* @Author: Yanpb
* @Date:   2025-08-08 16:13:59
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-08-08 16:45:45
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 110;
char g[N][N];
int n, m, res;

void dfs(int x, int y) {
	g[x][y] = '.';
	for (int i = -1; i <= 1; i ++)
		for (int j = -1; j <= 1; j ++)
		{
			int a = x + i, b = y + j;
			if(a >= 0 && a < n && b >= 0 && b < m && g[a][b] == 'W')
				dfs(a, b);
		}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i ++) scanf("%s", g[i]);

	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			if(g[i][j] == 'W')
			{
				dfs(i, j);
				res ++;
			}
	cout << res;
	return 0;
}