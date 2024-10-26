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
int n, m;
int h[N], e[M], ne[M], idx;
int dist[N], q[N];

void add(int a, int b) {
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx;
	idx ++;
}


// 手写队列实现
int bfs() {
	memset(dist, -1, sizeof dist);

	int tt = -1, hh = 0;

	q[0] = 1;
	dist[1] = 0;

	while(hh <= tt) {
		auto t = q[hh ++];
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if(dist[j] == -1) {
				dist[j] = dist[t] + 1;
				q[++ tt] = j;
			}
		}
	}
	return dist[n];
}

int bfs_stl() {
	memset(dist, -1, sizeof dist);
	queue<int> q;


	q.push(1);
	dist[1] = 0;
	while(q.size()) {
		auto t = q.front();
		q.pop();

		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			if (dist[j] == -1) {
				dist[j] = dist[t] + 1;
				q.push(j);
			}
		}
	}
	return dist[n];
}

void solved() {
	/* your code */
	std::cin >> n >> m;
	memset(h, -1, sizeof h);
	for (int i = 0; i < m; i ++) {
		int a, b;
		std::cin >> a >> b;
		add(a, b);
	}
	std::cout << bfs_stl() << std::endl;	
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}