/*
* @Author: Yanpb
* @Date:   2025-04-17 16:19:17
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-24 16:49:54
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 10;
int n;
int val[1 << N], win[1 << N];

// 使用 dfs 去给 value 数组去填写数值
// 也可以理解为 去建树
void dfs(int x) {
	if(x >= (1 << n)) return ;

	// 分别递归处理左子树 和 右子树
	dfs(2 * x), dfs(2 * x + 1);

	int l_val = val[2 * x], r_val = val[2 * x + 1];
	if(l_val > r_val) {
		val[x] = l_val;
		win[x] = win[2 * x];
	} else {
		val[x] = r_val;
		win[x] = win[2 * x + 1];
	}
	
}

int main() {
	cin >> n;
	for (int i = 0; i < (1 << n); i ++) {
		cin >> val[i + (1 << n)];
		win[i + (1 << n)] = i + 1;
	}
	dfs(1);
	cout << (val[2] > val[3] ? win[3] : win[2]);
	return 0;
}