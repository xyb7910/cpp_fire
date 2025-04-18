/*
* @Author: Yanpb
* @Date:   2025-04-18 22:20:03
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-18 22:26:58
*/
#include <iostream>
using namespace std;
const int N = 1e6 + 10;
int f[N];
int main() {
	int n; cin >> n;
	f[0] = 1;
	for (int i = 2; i <= n; i ++) {
		if(!(i & 1)) f[i] = min(f[i - 1], f[i / 2]) + 1;
		else f[i] = f[i - 1] + 1;
	}
	cout << f[n];
	return 0;
}