/*
* @Author: Yanpb
* @Date:   2025-04-23 14:47:56
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-23 14:48:00
*/
#include <iostream>
using namespace std;
const int N = 1e6 + 10;

struct Node {
    int left, right;
}tree[N];

// 前序遍历
void pre(int x) {
    if(!x) return ;
    cout << x << ' ';
    pre(tree[x].left);
    pre(tree[x].right);
}

// 中序遍历
void inor(int x) {
    if(!x) return ;
    inor(tree[x].left);
    cout << x << ' ';
    inor(tree[x].right);
}

// 中序遍历
void post(int x) {
    if(!x) return ;
    post(tree[x].left);
    post(tree[x].right);
    cout << x << ' ';
}

int main() {
    int n; cin >> n;
    for (int i = 1; i<= n; i ++) cin >> tree[i].left >> tree[i].right;
    pre(1); cout << endl;
    inor(1); cout << endl;
    post(1);
    return 0;
}