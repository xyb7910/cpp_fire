/*
* @Author: Yanpb
* @Date:   2025-04-23 10:49:52
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-23 10:50:13
*/
#include <iostream>
using namespace std;
const int N = 1e6 + 10;

struct Node {
    int left, right;
}tree[N];

// 返回以x为根的子树高度 最大高度等于 max(左子树的高度， 右子树的高度) + 1
int dfs(int x) {
    if(!x) return 0;
    int lh = dfs(tree[x].left), rh = dfs(tree[x].right);
    return max(lh, rh) + 1;
}

int main() {
    int n; cin >> n;
    for (int i = 1; i<= n; i ++) cin >> tree[i].left >> tree[i].right;
    cout << dfs(1);
    return 0;
}