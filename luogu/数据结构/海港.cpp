/*
* @Author: Yanpb
* @Date:   2025-03-28 13:22:22
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-28 14:21:07
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long i64;

const int N = 3e5 + 10;
int q[N][2], tt, hh; // q[i][0] 表示时刻， q[i][1] 表示国籍
i64 cnt[N], res;

int main() {
	int n; cin >> n;
	while(n --) {
		int t, k; cin >> t >> k;
		// 当队列不为空，当前时间已经超过 24 小时
		while(hh != tt && t - q[hh][0] >= 86400) {
			int na = q[hh][1]; // 取出队头国家
			cnt[na] --; 
			if(!cnt[na]) res --;

			hh ++; // 出队
			//  如果队头 >= N 则自动更新为 0
			if(hh == N) hh = 0;
		}

		for (int i = 0; i < k; i ++) {
			int x; cin >> x;
			// 将新元素入队，如果不存在这个国家
			// 总数加 1
			if(!cnt[x]) res ++;
			cnt[x] ++;

			q[tt][0] = t, q[tt][1] = x;
			tt ++;
			//  如果队尾 >= N 则自动更新为 0
			if(tt == N) tt = 0;
		}
		cout << res << endl;
	}
	return 0;
}