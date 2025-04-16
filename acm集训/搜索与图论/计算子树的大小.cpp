/*
* @Author: Yanpb
* @Date:   2025-04-16 00:25:37
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-16 00:30:23
*/
#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
vector<int> e[N];
int size[N];

void dfs(int u) {
	size[u] = 1;
	for (int i = 0; i < e[u].size(); i ++) {
		dfs(e[u][i]);
		size[u] += size[e[u][i]];
	}
}

int main() {
	int n; cin >> n;
	for (int i = 1, u, v; i < n; i ++) {
		cin >> u >> v; // u ==> v;
		e[u].push_back(v);
	}
	dfs(1);
	int x;
	cin >> x;
	cout << size[x] << endl;
	return 0;
}