#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int a[N];
bool st[N];
int n, m;

void dfs(int u) {
	if (u >= m) {
		for (int i = 0; i < m; i ++) {
			cout << a[i];
		}
		cout << endl;
		return ;
	}

	for (int i = 1; i <= n; i ++) {
		if(!st[i]) {
			a[u] = i;
			st[i] = true;
			dfs(u + 1);
			a[u] = 0;
			st[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	dfs(0);
	return 0;
}
