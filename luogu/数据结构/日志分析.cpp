/*
* @Author: Yanpb
* @Date:   2025-03-27 19:43:13
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-27 20:31:00
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 2e5 + 10;
int st[N], tt, w;

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i ++) {
		int op; cin >> op;
		if(op == 0)  {
			int x; cin >> x;
			int w = max(st[tt], x);
			st[++ tt] = w;
		}
		if(op == 1 && tt) tt --;
		if(op == 2) cout << st[tt] << endl;
	} 
	return 0;
}