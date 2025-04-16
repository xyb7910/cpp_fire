/*
* @Author: Yanpb
* @Date:   2025-04-16 00:14:25
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-16 00:24:05
*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
vector<int> e[N];
int deep[N], cnt[N], max_deep;

void dfs(int u) {
	for (int i = 0; i < e[u].size(); i ++) {
		deep[e[u][i]] = deep[u] + 1;
		cnt[deep[e[u][i]]] ++;
		dfs(e[u][i]);
	}
}

int main() {
	int n; cin >> n;
	for (int i = 1, u, v; i < n; i ++) {
		cin >> u >> v; // u ==> v;
		e[u].push_back(v);
	}
	deep[1] = 1, cnt[1] = 1;
	dfs(1);
	for (int i = 1; i <= 10000; i ++) {
		if(!cnt[i]) break;
		cout << cnt[i] << " ";
	} 
	return 0;
}