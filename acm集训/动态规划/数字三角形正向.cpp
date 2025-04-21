/*
* @Author: Yanpb
* @Date:   2025-04-20 18:39:10
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-20 19:27:03
*/
#include <iostream>
using namespace std;

const int N = 1010;

int n;
int w[N][N], f[N][N];

void input() {
	cin >> n;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= i; j ++)
			cin >> w[i][j];
}

void work() {
	f[1][1] = w[1][1];

	for (int i = 2; i <= n; i ++)
		for (int j = 1; j <= n; j ++) {
			f[i][j] = f[i - 1][j];
			if(j - 1 >= 1) f[i][j] = max(f[i][j], f[i - 1][j - 1]); 

			f[i][j] += w[i][j];
		}
	int ans = -1;
	for (int i = 1; i <= n; i ++) ans = max(ans, f[n][i]);
	cout << ans;
}


int main() {
	input();
	work();
	return 0;
}