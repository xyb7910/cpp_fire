/*
* @Author: Yanpb
* @Date:   2025-03-27 20:48:00
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-28 13:09:29
*/
#include <iostream>
using namespace std;
const int N = 1010;
int q[N], tt, hh, res;
bool st[N]; // 判断队列之中是否存储当前元素
int n, k;
int main() {
	cin >> k >> n;
	for (int i = 0; i < n; i ++) {
		int x; cin >> x;
		// 如果队列之中存在元素
		if(hh <= tt) {
			if(st[x]) continue; // 队列之中存在这个元素
			else
			{
				if(tt - hh + 1 == k) st[q[hh]] = 0, hh ++; // 队列长度等于 k，则将队头出队
				q[++ tt] = x, st[x] = 1, res ++;
			}
		}
		else // 队列之中没有元素 
		{
			q[++ tt] = x;
			st[x] = 1;
			res ++;
		}
	}
	cout << res;
	return 0;
}