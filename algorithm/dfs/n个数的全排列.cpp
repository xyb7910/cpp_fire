#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 10;
int n;
int num[N], a[N];
bool st[N];

void dfs(int num[], int u) {
	if(u == n + 1) {
		for (int i = 1; i <= n; i ++) {
			cout << a[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = 1; i <= n; i ++) {
		if(!st[i]) {
			a[u] = num[i];
			st[i] = true;
			dfs(num, u + 1);
			a[u] = 0;
			st[i] = false;
		}
	}
}

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> num[i];
	sort(num + 1, num + n + 1);
	dfs(num, 1);
	return 0;
}