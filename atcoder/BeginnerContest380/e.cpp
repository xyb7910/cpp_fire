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
const int N = 5e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int fa[N], cnt[N], l[N], r[N];
int col[N], col_cnt[N]; // col_cnt[i]: 颜色i的数量 col[i]:节点i的颜色

int _find(int x) {
    return x == fa[x] ? x : fa[x] = _find(fa[x]);
}

// 将x染成c颜色
void paint(int x, int c) {
    x = _find(x);
    col_cnt[col[x]] -= cnt[x];
    col[x] = c;
    col_cnt[c] += cnt[x];
}

void _union(int x, int y) {
    int fx = _find(x), fy = _find(y);
    fa[fx] = fy;
    l[fy] = min(l[fx], l[fy]), r[fy] = max(r[fx], r[fy]);
    cnt[fy] += cnt[fx]; 
}

void solved() {
    /* your code */
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i ++) {
        col[i] = fa[i] = l[i] = r[i] = i;
        cnt[i] = 1, col_cnt[i] = 1;
    }

    while(q --) {
        int op; cin >> op;
        if(op == 1) {
            int x, c;
            cin >> x >> c;
            paint(x, c);
            int L = l[_find(x)], R = r[_find(x)];
            if(col[_find(L - 1)] == c) _union(L - 1, x);
            if(col[_find(R + 1)] == c) _union(R + 1, x);
        } else {
            int c; cin >> c;
            cout << col_cnt[c] << endl;
        }
    }

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}