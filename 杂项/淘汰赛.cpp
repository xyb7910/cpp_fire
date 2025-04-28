/*
* @Author: Yanpb
* @Date:   2025-04-27 14:41:48
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-27 14:49:05
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n;
int winner[N], val[N];

void dfs(int x) {
	if(x >= 1 << n) return ;
	dfs(2 * x); // 左子树
	dfs(2 * x + 1); // 右子树

	int lval = val[2 * x], rval = val[2 * x + 1];
	if(lval > rval) {
		val[x] = lval;
		winner[x] = winner[2 * x];
	} else {
		val[x] = rval;
		winner[x] = winner[2 * x + 1];
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < (1 << n); i ++) {
		cin >> val[i + (1 << n)];
		winner[i + (1 << n)] = i + 1;
	}
	dfs(1);
	cout << (val[2] > val[3] ? winner[3] : winner[2]);
	return 0;
}