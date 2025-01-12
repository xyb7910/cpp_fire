/*
* @Author: Yanpb
* @Date:   2025-01-12 15:50:39
* @Last Modified by:   Hetao
* @Last Modified time: 2025-01-12 18:24:15
*/
// DFS 求连通块
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1e3 + 10;
char g[N][N];
int  idx[N][N];
int n, m;

void dfs(int x, int y, int cnt) {
	// 出界
	if(x < 0 || x >= n || y < 0 || y >= m) return ;
	// 不是石油 或者 已经被遍历过
	if(idx[x][y] > 0 || g[x][y] != '@') return ;
	// 标记当前节点
	idx[x][y] = cnt;

	// 八联通分量
	for (int i = -1; i <= 1; i ++)
		for (int j = -1; j <= 1; j ++) {
			if(i != 0 || j != 0) dfs(x + i, y + j, cnt);
		}

}

int main() {
	while(scanf("%d %d", &n, &m) == 2 && n && m) {
		for (int i = 0; i < n; i ++) scanf("%s", &g[i]);
		 
		memset(idx, 0, sizeof(idx));
		int cnt = 0;

		for (int i = 0; i < n; i ++)
			for (int j = 0; j < m; j ++)
				if(g[i][j] == '@' && idx[i][j] == 0) dfs(i, j, ++ cnt);	
				
		printf("%d\n", cnt);
	}
	return 0;
}