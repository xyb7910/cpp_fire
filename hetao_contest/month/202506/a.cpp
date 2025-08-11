/*
* @Author: Yanpb
* @Date:   2025-06-30 12:18:46
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-06-30 13:17:49
*/
#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, l[N], h;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> l[i];
	cin >> h;
	while(h) cout << h << " \n"[!l[h]], h = l[h];
	return 0;
}