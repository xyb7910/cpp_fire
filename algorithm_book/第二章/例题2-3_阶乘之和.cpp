#include <iostream>
#include <cstring>
#include <algorithm>
#include <time.h>

using namespace std;
// 输入n， 计算 S = 1! + 2! + 3! + ... + n! 的末尾六位（不含前导零）。 n <= 10 ^ 6
const int N = 1e6;
typedef long long LL;
int n, sum;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int res = 1;
		for (int j = 1; j <= i; j ++) {
			res = res * j % N;
		}
		sum = (res + sum) % N;
	}
	// sum %= N;
	cout << sum << endl;
	printf("Time used = %.2lf\n", (double)clock() / CLOCKS_PER_SEC);
	return 0;
}