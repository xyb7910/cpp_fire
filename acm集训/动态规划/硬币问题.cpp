/*
* @Author: Yanpb
* @Date:   2025-04-18 21:03:48
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-18 21:53:19
*/
#include <iostream>
using namespace std;
/*
我们可以使用的钱为1，5，11。
要解决凑够 n 元钱的问题，如果知道一下以下几组数据：
代价： 凑足 n 元至少需要几枚硬币。
- n - 1 的代价 a。 外加一枚 1 元的硬币可以到 n 元
- n - 5 的代价 b。 外加一枚 5 元的硬币可以到 n 元
- n - 11 的代价 c。 外加一枚 11 元的硬币可以到 n 元

那么，凑 n 元的代价为：
	min(a + 1, b + 1, c + 1);

f(n) 表示凑出 n 元钱需要的硬币个数
*/
const int N = 1e6 + 10;

int f[N];

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		f[i] = f[i - 1] + 1;
		if(i - 5 >= 0) f[i] = min(f[i], f[i - 5] + 1);
		if(i - 11 >= 0) f[i] = min(f[i], f[i - 11] + 1);
	}
	cout << f[n];
	return 0;
}