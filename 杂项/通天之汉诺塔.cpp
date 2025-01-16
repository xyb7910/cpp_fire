/*
* @Author: Yanpb
* @Date:   2025-01-16 18:54:02
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-16 18:58:48
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

int res[N] = {1}; // res[0] = 1;

int main() {
	int n; cin >> n;
	int cnt = 1; // 计算的长度
	for (int k = 1; k <= n; k ++) {
		for (int i = 0; i < cnt; i ++) res[i] *= 2;
		for (int i = 0; i < cnt; i ++) {
			res[i + 1] += res[i] / 10;
			res[i] %= 10;
		}
		if(res[cnt]) cnt ++;
	}
	res[0] --;
	for (int i = cnt - 1; ~i; i --) cout << res[i];
	return 0;
}