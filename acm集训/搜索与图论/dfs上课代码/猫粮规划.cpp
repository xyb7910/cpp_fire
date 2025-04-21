/*
* @Author: Yanpb
* @Date:   2025-04-21 16:58:50
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-21 18:39:38
*/
#include <iostream>
#include <cstdio>

using namespace std;
const int N = 50;
int n, l, r, cnt;
int nums[N], st[N];

void dfs(int u) {
	int sum = 0;
	for (int i = 1; i < u; i ++) {
		sum += nums[i] * st[i];
	}

	if(sum > r) return ;
	
	if(u > n) {
		if(sum >= l) cnt ++;
		return ;
	}

	for (int i = 0; i <= 1; i ++) {
		st[u] = i;
		dfs(u + 1);
	}
}

int main() {
	cin >> n >> l >> r;
	for (int i = 1; i <= n; i ++) scanf("%d", nums + i);
	dfs(1);
	cout << cnt;
	return 0;
}