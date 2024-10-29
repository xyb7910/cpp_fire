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
const int N = 2e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int n, last;

struct Node{
	int l, r;
	int v; // 维护区间[l, r]的最大值
}tr[N * 4];

void pushup(int u) { // 由子节点的信息
	tr[u].v = max(tr[u << 1].v, tr[u << 1 | 1].v);
}

// 新建一个节点为u, 区间为 [l, r]
void build(int u, int l, int r) {
	tr[u] = {l, r};
	// 是叶子节点
	if(l == r) return;
	int mid = l + r >> 1;
	build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

// 查询区间 [l, r] 之间的最大值
int query(int u, int l, int r) {
	if(l <= tr[u].l && r >= tr[u].r) return tr[u].v;

	int mid = tr[u].l + tr[u].r >> 1;
	int v = 0;
	if(l <= mid) v = query(u << 1, l, r);
	if(r > mid) v = max(v, query(u << 1 | 1, l, r));

	return v;
}

// 修改第 x 个节点为 v
void modify(int u, int x, int v) {
	if(tr[u].l == x && tr[u].r == x) tr[u].v = v;
	 else {
	 	int mid = tr[u].l + tr[u].r >> 1;
	 	if(x <= mid) modify(u << 1, x, v);
	 	else modify(u << 1 | 1, x, v);
	 	pushup(u);
	 }
}

void solved() {
    /* your code */
    int m, p;
    std::cin >> m >> p;
    build(1, 1, m);
    while(m --) {
    	char op[2];
    	int x;
    	std::cin >> op >> x;
    	if(*op == 'Q') {
    		last = query(1, n - x + 1, n);
    		std::cout << last << std::endl;
    	} else {
    		modify(1, n + 1, ((LL)last + x) % p);
    		n ++;
    	}
    }
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}