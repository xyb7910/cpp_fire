#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10,  M = 2e5 + 10;
int n, m;
int p[N];

struct Edge {
	int a, b, w;
	bool operator<(const Edge& W) const {
		return w < W.w;
	}
}edges[M];

int find(int x) {
	return p[x] != x ? p[x] = find(p[x]) : p[x];
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) p[i] = i;
	for (int i = 0; i < m; i ++) {	
		int a, b, w;
		cin >> a >> b >> w;
		edges[i] = {a, b, w};
	}
	sort(edges, edges + m);
	int res = 0, cnt = 1;
	for (int i = 0; i < m; i ++) {
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		a = find(a), b = find(b);
		if (a != b) {
			p[a] = b;
			res += w;
			cnt ++;
		}
	}
	if(cnt == n) cout << res << endl;
 	else  puts("impossible");
	return 0;
}