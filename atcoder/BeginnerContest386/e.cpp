/*
* @Author: Yanpb
* @Date:   2025-01-17 18:00:54
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-17 18:22:29
*/
#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;
const int N = 2e5 + 10;
typedef long long i64;
int n, k; 
i64 a[N];
i64 ans;

void dfs(int pos, int k, i64 sum) {
	if(k == 0) {
		ans = max(ans, sum);
		return ;
	}
	for (int i = pos + 1; i <= n; ++ i) {
		dfs(i, k - 1, sum ^ a[i]);
	}
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; ++ i) cin >> a[i];

	if(k < n / 2) {
		dfs(0, k, 0);
	} else {
		i64 xor_sum = 0;
		for (int i = 0; i <= n; ++ i)
			xor_sum ^= a[i];
		dfs(0, n - k, xor_sum);
	}
	cout << ans << endl;
	return  0;
}