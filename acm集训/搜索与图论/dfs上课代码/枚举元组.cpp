/*
* @Author: Yanpb
* @Date:   2025-04-21 19:01:02
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-21 19:07:52
*/
#include <iostream>
using namespace std;

const int N = 10;
int n, k;
int nums[N];

void dfs(int u) {
	if(u > n) {
		for (int i = 1; i <= k; i ++) cout << nums[i] << " ";
		cout << endl;
		return ;	
	}

	for (int i = 1; i <= n; i ++) {
		nums[u] = i;
		dfs(u + 1);
	}
}

int main() {
	cin >> k >> n;
	dfs(1);
	return 0;
}