/*
* @Author: Yanpb
* @Date:   2025-04-16 11:15:43
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-16 15:46:50
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

/*
**滑动窗口（队列）**
使用一个队列来维护优惠卷的区间。

- 如果当前记录是火车，则加入队列；
- 如果当前记录是公交车，则线性扫描一下队列中的所有优惠卷，找到
	第一个未被使用过的并且大于等于当前价格的优惠卷即可；
- 使用一个 $bool$ 类型的数组对优惠卷进行判重，确保每一个优惠卷最多只会被使用一次。

时间负责度分析：
 - 在最坏情况下，对于每一个公交车记录，都要扫描一下队列中的所有优惠卷，
 队列中的优惠卷个数最多为 $45$ 个，因此时间负责度为 $O(45N)$。
*/

struct Ticket {
	int time, price;
	bool used;
}q[N];

int n;

void solved() {
    /* your code */
	scanf("%d", &n);

	int res = 0;
	for (int i = 0, r = 0, l = 0; i < n; i ++) {
		int type, price, time;
		scanf("%d%d%d", &type, &price, &time);
		// 如果是火车,则将优惠卷加入队列中
		if(!type) {
			q[r ++] = {time, price};
			res += price;
		} else {
			// 如果是公交车,首先删除队列中在 当前时间45分钟之前的时间
			while(l < r && q[l].time < time - 45) l ++;

			bool success = 0;
			// 遍历一边队列，查看是否存在优惠卷
			for (int j = l; j < r; j ++) {
				if(q[j].price >= price && !q[j].used) {
					q[j].used = 1;
					success = 1;
					break;
				}
			}
			// 如果没有对应的优惠卷则付费
			if(!success) res += price;
		}
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}