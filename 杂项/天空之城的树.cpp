/*
* @Author: Yanpb
* @Date:   2025-04-23 17:04:25
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-23 17:10:55
*/
#include <iostream>
#include <cstring>
#include <algorithm>

#define x first
#define y second

using namespace std;
const int N = 1e3 + 10;
typedef pair<int, int> PII;
PII t[N];

int dfs(int u) {
	if(!u) return 0;
	int lh = dfs(t[u].x);
	int rh = dfs(t[u].y);
	return max(lh, rh) + 1;
}

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> t[i].x >> t[i].y; 
	}
	cout << dfs(1);
	return 0;
}