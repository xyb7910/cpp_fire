/*
* @Author: Yanpb
* @Date:   2025-04-27 14:53:38
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-27 15:02:46
*/
#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
vector<int> e[N];
bool st[N];
int ans, n, d;

void dfs(int u, int dis) {
	st[u] = 1;
	if(d == dis) return ;
	for (int i = 0; i < e[u].size(); i ++) {
		if(!st[e[u][i]]) {
			dfs(e[u][i], dis + 1);
			ans ++;
		}
	}
}

int main() {
	int n; cin >> n >> d;
	for (int i = 1, u, v; i < n; i ++) {
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs(1, 0);
	cout << ans;
	return 0;
}