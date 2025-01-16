/*
* @Author: Yanpb
* @Date:   2025-01-16 19:04:46
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-16 19:14:05
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int res[N] = {1};

int main() {
	int a, n; cin >> a >> n;
	int cnt = 1;
	for (int k = 1; k <= n; k ++) {
		for (int i = 0; i < cnt; i ++) res[i] *= a;
		for (int i = 0; i < cnt; i ++) {
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
		if(res[cnt]) cnt ++;
	}
	int odd_cnt = 0;
	for (int i = 0; i < cnt; i ++) if(res[i] & 1) odd_cnt ++;
	cout << odd_cnt * 2 - cnt;
	return 0;
}