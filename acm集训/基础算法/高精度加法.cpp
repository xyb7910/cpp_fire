#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

string a, b;
int A[N], B[N], ans[N];
int l1, l2;

int main() {
	cin >> a >> b;
	int n = a.size(), m = b.size();
	// 倒序存储
	for (int i = n - 1; i >= 0; i --) A[l1 ++] = a[i] - '0';
	for (int i = m - 1; i >= 0; i --) B[l2 ++] = b[i] - '0';
	
	// 计算多少次
	int l = max(l1, l2);

	// 先计算加法
	for (int i = 0; i < l; i ++)
		ans[i] = A[i] + B[i];

	// 考虑进位 与 保留位
	for (int i = 0; i < l; i ++) {
		// 进位
		ans[i + 1] += ans[i] / 10;
		// 保留位
		ans[i] %= 10;
	}	

	// 最高位是否有进位
	if(ans[l]) l ++;

	// 特殊数据 ： 1. 0012 + 02 = 14  2. 000 + 0 = 0
	while(ans[l] == 0 && l > 0) l --;
	// 倒序输出答案
	for (int i = l; i >= 0; i --) cout << ans[i];
	return 0;
}