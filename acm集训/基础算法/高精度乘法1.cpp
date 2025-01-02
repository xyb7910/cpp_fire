// 使用数组模拟高精度乘法：
//  高精度数字乘单精度数字
#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int A[N], l;

int main() {
	string a; cin >> a;
	// 将字符串转化为数字存储在数组中
	for (int i = a.size() - 1; ~i; i --) A[l ++] = a[i] - '0';
	int b; cin >> b;
	if(b) l += log10(b);
	// 先进行乘法
	for (int i = 0; i < l; i ++)
		A[i] *= b;

	// 在考虑进位
	for (int i = 0; i < l; i ++) {
		// 先进位后存储，不然BBQ
		A[i + 1] += A[i] / 10;
		A[i] %= 10;
	}
	// 判断是否存在前导零
	while(l > 0 && A[l] == 0) l --;
	for (int i = l; ~i; i --) cout << A[i];
		
	return 0;
}
