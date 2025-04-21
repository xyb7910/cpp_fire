/*
* @Author: Yanpb
* @Date:   2025-04-21 14:15:02
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-21 14:20:44
*/
#include <iostream>
#include <vector>
using namespace std;

const int N = 1e4 + 10;
vector<int> node[N];

void dfs(int u) {
	cout << u << " ";
	for (int i = 0; i < node[u].size(); i ++) {
		dfs(node[u][i]);
	}
}


int main() {
	int n; cin >> n;
	for (int i = 2; i <= n; i ++) {
		int father; cin >> father;
		node[father].push_back(i); // father ==> i
	}
	dfs(1); // 以深度优先的方式 输出当前节点
	return 0;
}