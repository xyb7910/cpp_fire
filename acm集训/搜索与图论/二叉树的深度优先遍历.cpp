/*
* @Author: Yanpb
* @Date:   2025-04-15 23:35:09
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-15 23:40:39
*/
#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 10;
int n, fa;
vector<int> e[N];

void dfs(int u) {
	cout << u << ' ';
	for (int i = 0; i < e[u].size(); i ++)
		dfs(e[u][i]);
}

int main() {
	cin >> n;
	for (int i = 2; i <= n; i ++) {
		cin >> fa;
		e[fa].push_back(i);
	}
	dfs(1);
	return 0;
}