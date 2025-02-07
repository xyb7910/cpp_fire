/*
* @Author: Yanpb
* @Date:   2025-02-07 18:03:43
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-07 18:28:20
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int n, res;
int num[N];
int s[N][11];

void dfs(int u, int sum) { // 表示到第几个调料， 总和为多少
	if(sum > n) return ;
	if(u > 10) {
		if(sum == n) {
			res ++;
			for (int i = 1; i <= 10; i ++) {
				s[res][i] = num[i];
			}
		}
		return ;
	}

	for (int i = 1; i <= 3; i ++) {
		num[u] = i;
		dfs(u + 1, sum + i);
		num[u] = 0;
	}
}

int main() {
	cin >> n;
	dfs(1, 0);
	cout << res << endl;
	for (int i = 1; i <= res; i ++) {
		for (int j = 1; j <= 10; j ++) {
			cout << s[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}