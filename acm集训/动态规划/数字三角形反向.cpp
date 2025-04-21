/*
* @Author: Yanpb
* @Date:   2025-04-20 19:41:27
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-20 19:47:22
*/
#include <iostream>
using namespace std;

const int N = 1e3 + 10;
int w[N][N], f[N][N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= i; j ++) {
			cin >> w[i][j];
		}

	for (int i = n; i; i --)
		for (int j = i; j; j --)
			f[i][j] = max(f[i + 1][j], f[i + 1][j + 1]) + w[i][j];
	cout << f[1][1];
	return 0;
}