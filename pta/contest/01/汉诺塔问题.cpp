/*
* @Author: Yanpb
* @Date:   2025-05-08 13:34:59
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-05-08 14:04:56
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
int n;


// dfs 函数执行移动盘子的操作，并且会统计移动次数
int dfs(int n, char source, char target, char auli) {
	// 先设计递归出口
	if(n == 1) {
		printf("%c->1->%c\n", source, target);
		return 1;
	}
	// 在设计递归部分
	int cnt = 0;
	// 首先将 n-1 个盘子从 来源柱 移动到辅助柱
	cnt += dfs(n - 1, source, auli, target);
	// 对最底下的盘子进行操作
	printf("%c->%d->%c\n", source, n, target);
	// 操作次数 + 1
	cnt += 1;
	// 在将辅助柱 上的 n-1 进行操作
	cnt += dfs(n - 1, auli, target, source);
	return cnt;
}


int main() {
	cin >> n;
	cout << dfs(n, 'a', 'b', 'c');
	return 0;
}