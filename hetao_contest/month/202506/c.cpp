/*
* @Author: Yanpb
* @Date:   2025-06-30 12:19:01
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-06-30 13:32:28
*/
#include <iostream>
using namespace std;
const int N = 1e5 + 10;
int n, w[N], l[N], st[N];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int id; cin >> id >> w[id] >> l[id];
	}
	int m; cin >> m;
	for (int i = 1; i <= m; i ++) {
		int id; cin >> id;
		st[id] = 1;
	}
	for (int i = 1; i != -1; i = l[i])
		if(!st[i])cout << w[i] << " ";
	return 0;
}