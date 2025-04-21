/*
* @Author: Yanpb
* @Date:   2025-04-21 16:28:20
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-21 16:39:54
*/
#include <iostream>
using namespace std;
const int N = 20;
int n, k;
int nums[N], used[N];

void dfs(int u) {
	if(u > k) {
		for (int i = 1; i <= k; i ++)
			cout << nums[i] << " ";
		cout << endl;
		return ;
	}

	for (int i = 1; i <= n; i ++) {
		if(!used[i]) {
			used[i] = 1;
			nums[u] = i;
			dfs(u + 1);
			used[i] = 0; 
		}
	}
}

int main() {
	cin >> n >> k;
	dfs(1);
	return 0;
}