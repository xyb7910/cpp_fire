/*
* @Author: Yanpb
* @Date:   2025-04-21 14:43:17
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-21 14:49:08
*/
#include <iostream>
#include <vector>

using namespace std;
const int N = 10010;
vector<int> node[N];
int deep[N], cnt[N];
int n;
void dfs(int u) {
	for (int i = 0; i < node[u].size(); i ++) {
		deep[node[u][i]] = deep[u] + 1;
		cnt[deep[node[u][i]]] ++;
		dfs(node[u][i]);
	}
}

int main() {
	cin >> n;
	for (int i = 1, u, v; i < n; i ++) {
		cin >> u >> v; // u ==> v
		node[u].push_back(v);
	}
	deep[1] = 1, cnt[1] = 1;
	dfs(1);
	for (int i = 1; cnt[i]; i ++) cout << cnt[i] << " ";
	return 0;
}