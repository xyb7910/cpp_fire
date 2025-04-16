/*
* @Author: Yanpb
* @Date:   2025-04-15 23:14:25
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-15 23:33:04
*/
#include <iostream>
#include <vector>

using namespace std;
const int N = 1e5 + 10;
vector<int> child[N];
int father[N];

int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int u, v; cin >> u >> v; // u ==> v
		father[v] = u;
		child[u].push_back(v);
	}

	int x; cin >> x;
	// 输出 结点x 的父节点
	cout << father[x] << endl;

	// 输出 结点x 的所有子节点
	for (int i = 0; i < child[x].size(); i ++) {
		cout << child[x][i] << " ";
	}
	cout << endl;

	// 如果为森林可以输出所有的根结点
	for (int i = 1; i <= n; i ++) if(!father[i]) cout << i;
	cout << endl;
	
	// 输出所有的叶子结点
	for (int i = 1; i <= n; i ++) {
		if(!child[i].size()) cout << i << " ";
	}
	cout << endl;
	return 0;
}
