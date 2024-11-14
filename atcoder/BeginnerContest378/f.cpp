#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 2e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

std::vector<int> G[N];
int deg[N];
bool visit[N];
LL cnt, ans;

void dfs(int v, int fa = 0) {
	if(deg[v] != 3) {
		// v是一个周边的点
		cnt += (deg[v] == 2);
		return ;
	}

	visit[v] = 1;
	for (auto x : G[v]) {
		if(x == fa) continue;
		dfs(x, v);
	}
}

void solved() {
	/* your code */
	int n;
	cin >> n;
	for (int i = 1; i < n; i ++) {
		int u, v;
		cin >> u >> v;
		G[u].push_back(v); G[v].push_back(u);
		deg[u] ++, deg[v] ++;
	}

	for (int i = 1; i <= n; i ++) {
		//找度数为3的连通块
		if(deg[i] != 3) continue;	
		if(visit[i]) continue;
		cnt = 0;
		dfs(i);
		ans += 1LL * cnt * (cnt - 1) / 2; 
	}
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}