/*
* @Author: Yanpb
* @Date:   2025-04-16 10:14:04
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-16 10:29:23
*/
#include <iostream>
#include <vector>

using namespace std;
const int N = 1010;
vector<int> e[N];
int a[N], b[N], c[N];

void dfs(int u) {
	cout << char(u);
	for (int i = 0; i < e[u].size(); i ++) {
		dfs(e[u][i]);
	}
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		string s; cin >> s;
		a[i] = s[0]; b[i] = s[1]; c[i] = s[2];
		if(b[i] != '*') e[a[i]].push_back(b[i]);
		if(c[i] != '*') e[a[i]].push_back(c[i]);
	}
	dfs(a[1]);
	return 0;
}