#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
// 输出所有形如 aabb 的四位完全平方数字。
const int N = 1e5 + 10;
typedef long long LL;
int n;
double m;

// 方法一：使用使用开平方 sqrt 函数
// int main() {
// 	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
// 	for (int i = 1; i <= 9; i ++) {
// 		for (int  j = 1; j <= 9; j ++) {
// 			n = i * 1100 + j * 11;
// 			m = sqrt(n);
// 			if(floor(m + 0.5) == m) cout << n << endl; 
// 			// floor(m + 0.5) 满足四舍五入，浮点数操作存在误差
// 		}
// 	}
// 	return 0;
// }

// 避免使用浮点数，直接使用整数进行乘法
int main() {
	for (int i = 1; ; i ++) {
		n = i * i;
		if(n < 1000) continue;
		if(n > 9999) break;

		int height = n / 100;
		int low = n % 100;
		if (height / 10 == height % 10 && low / 10 == low % 10) cout << n << endl;
	}
	return 0;
}