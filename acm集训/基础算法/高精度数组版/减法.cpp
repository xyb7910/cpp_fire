/*
* @Author: Yanpb
* @Date:   2025-01-10 18:50:28
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-10 19:16:52
*/
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

string a, b;
int A[N], B[N], C[N], l1, l2;
bool neg;

int main() {
	cin >> a >> b;
	// 确保 大数字 - 小数字
	if(a.size() < b.size() || a.size() == b.size() && a < b) {
		neg = 1;
		swap(a, b);
	}
	int n = a.size(), m = b.size();
	// 倒序存储
	for (int i = n - 1; i >= 0; i --) A[l1 ++] = a[i] - '0';
	for (int i = m - 1; i >= 0; i --) B[l2 ++] = b[i] - '0';

	// 最大计算多少次
	int l = n;
	int t = 0;
	for (int i = 0; i < l; i ++) {
		int diff = A[i] - B[i] - t; // 表示本位差值
		if(diff < 0) {
			diff += 10;
			t = 1;
		} else {
			t = 0;
		}
		C[i] = diff;
	}

	// 删除前导零
	while(l > 0 && C[l] == 0) l --;
	if(neg) cout << "-";
	for (int i = l; i >= 0; i --) cout << C[i];
	return 0;
}