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
const int N = 1e5 + 10, M = 2 * N;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
bool st[N];

// 树 or 图的深度优先搜索
/*
void dfs(int u) {
	st[u] = true;
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!st[j]) {
			dfs(j);
		}
	}
}
*/


int h[N], e[M], ne[M], idx;
int n, ans = N;
void add(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx ++;
}

// 返回以 u 为跟的子树中点的数量
int dfs(int u) {
	st[u] = true;
	int sum = 1, res = 0; // 当前连通块的值
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if(!st[j]) {
			int s = dfs(j);
			res = max(res, s);
			sum += s;
		}
	}
	res = max(res, n - sum);
	ans = min(ans, res);
	return sum;	
}

void solved() {
	/* your code */
	std::cin >> n;
	memset(h, -1, sizeof h);
	for (int i = 0; i < n - 1; i ++) {
		int a, b;
		std::cin >> a >> b;
		add(a, b), add(b, a);
	}

	dfs(1);
	std::cout << ans << std::endl;

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}