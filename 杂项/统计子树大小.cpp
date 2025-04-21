/*
* @Author: Yanpb
* @Date:   2025-04-21 14:59:58
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-21 15:03:24
*/
#include <iostream>
#include <vector>

using namespace std;
const int N = 1e4 + 10;
int n;
vector<int> node[N];
int size[N];

void dfs(int u) {
	size[u] = 1;
	for (int i = 0; i < node[u].size(); i ++) {
		dfs(node[u][i]);
		size[u] += size[node[u][i]];
	}
}

int main() {
	cin >> n;
	for (int i = 1, u, v; i < n; i ++) {
		cin >> u >> v;
		node[u].push_back(v);
	}
	dfs(1);
	int x;
	cin >> x;
	cout << size[x];
	return 0;
}