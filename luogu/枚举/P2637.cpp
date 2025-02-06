/*
* @Author: Yanpb
* @Date:   2025-02-01 21:07:44
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-02-01 21:44:52
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1010;
int n, m;

int prices[N];

int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i ++) cin >> prices[i];
	sort(prices, prices + m);
	int p = 0, res = 0;
	for (int i = 0; i < m; i ++) { // 价格
	    int cnt = 0, price = prices[i];
		for (int j = 0; j < m; j ++) { // 物品
			if(price <= prices[j] ) cnt ++; //个数加一
		}
		if(cnt >= n) cnt = n; // 防止买主过多
		if(cnt * price > res) {
		    p = price, res = cnt * price;
		}
	}
	cout << p << " " << res;
	return 0;
}