/*
* @Author: Yanpb
* @Date:   2025-04-21 14:31:51
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-21 14:37:21
*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e4 + 10;
int n;
vector<int> node[N];
int deep[N];

void dfs(int u) {
	for (int i = 0; i < node[u].size(); i ++) {
		deep[node[u][i]] = deep[u] + 1;
		dfs(node[u][i]);
	}
}

int main() {
	cin >> n;
	for (int i = 1, u, v; i < n; i ++) {
		cin >> u >> v; // u ==> v
		node[u].push_back(v);
	}
	deep[1] = 1; // 1 or 0
	dfs(1);
	for (int i = 1; i <= n; i ++) cout << deep[i] << " ";
	return 0;
}