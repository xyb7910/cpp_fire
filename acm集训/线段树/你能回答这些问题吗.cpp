#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 5e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, m;
int w[N];

struct Node{
	int l, r;
	int sum; // 表示区间[l, r]的和
	int lmax; // 左节点的最大后缀 
	int rmax; // 右节点的最大前缀
	int tmax; // 用来存储当前区间[l, r]的最大连续字段和
}tr[N * 4];

void pushup(Node& u, Node& l, Node& r) {
	u.sum = l.sum + r.sum;
	u.lmax = max(l.lmax, l.sum + r.lmax);
	u.rmax = max(r.rmax, r.sum + l.rmax);
	u.tmax = max(l.rmax + r.lmax, max(l.tmax, r.tmax));
}

void pushup(int u) {
	pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
	if(l == r) tr[u] = {l, r, w[r], w[r], w[r], w[r]};
	else {
		tr[u] = {l, r};
		int mid = l + r >> 1;
		build(u << 1, l, mid);
		build(u << 1 | 1, mid + 1, r);
		pushup(u);
	}
}

void modify(int u, int x, int v) {
	if(tr[u].l == x && tr[u].r == x) tr[u] = {x, x, v, v, v, v};
	else {
		int mid = tr[u].l + tr[u].r >> 1;
		if(x <= mid) modify(u << 1, x, v);
		else modify(u << 1 | 1, x, v);
		pushup(u);
	}
}

Node query(int u, int l, int r) {
	if(tr[u].l >= l && tr[u].r <= r) return tr[u];
	else {
		int mid = tr[u].l + tr[u].r >> 1;
		if(r <= mid) return query(u << 1, l, r);
		else if(l > mid) return query(u << 1 | 1, l, r);
		else {
			auto left = query(u << 1, l, r);
			auto right = query(u << 1 | 1, l, r);
			Node res;
			pushup(res, left, right);
			return res;
		}
	}
}

void solved() {
    /* your code */
    std::cin >> n >> m;
    for (int i = 1; i <= n; i ++) std::cin >> w[i];
    build(1, 1, n);
    
    while(m --) {
    	int k, x, y;
    	std::cin >> k >> x >> y;
    	if(k == 1) {
    		if(x > y) swap(x, y);
    		Node res = query(1, x, y);
    		std::cout << res.tmax << std::endl;
    	} else {
    		modify(1, x, y);
    	}
    }	
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}
