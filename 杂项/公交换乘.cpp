/*
* @Author: Yanpb
* @Date:   2025-04-16 16:01:41
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-16 16:12:00
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

/*
假如现在时间为 i， [i - 45, i] 的优惠卷
都可以使用。
*/
const int N = 1e5 + 10;
struct Ticket {
	int time, price;
	bool used;
}q[N];

int n;

int main() {
	cin >> n;
	int res = 0;
	for (int i = 0, l = 0, r = 0; i < n; i ++) {
		int type, price, time;
		cin >> type >> price >> time;
		if(!type) {
			q[r ++] = {time, price};
			res += price;
		} else {
			while(l < r && time - q[l].time > 45) l ++;

			bool success = 0;
			for (int j = l; j < r; j ++) {
				if(!q[j].used && q[j].price >= price) {
					q[j].used = 1;
					success = 1;
					break;
				}
			}
			if(!success) res += price;
		}
	}
	cout << res;
	return 0;
}