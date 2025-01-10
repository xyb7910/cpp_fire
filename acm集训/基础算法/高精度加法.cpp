#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
string a, b; // 将输入视为一个字符串
int A[N], B[N], ans[N]; // 分别存储两个加数，以及和
int l1, l2; // 表示A，B数组分别存储到哪一位了

int main() {
	cin >> a >> b;
	int n = a.size(), m = b.size();
	// 1.倒序存储
	for (int i = n - 1; i >= 0; i --) A[l1 ++] = a[i] - '0';
	for (int i = m - 1; i >= 0; i --) B[l2 ++] = b[i] - '0';
	// 2.计算结果的最大长度
	int l = max(l1, l2);
	// 3.先计算加法
	for (int i = 0; i < l; i ++)
		ans[i] = A[i] + B[i];
	// 4.考虑进位 与 保留位
	for (int i = 0; i < l; i ++) {
		// 一定要先进位再处理保留位
		// 进位
		ans[i + 1] += ans[i] / 10;
		// 保留位
		ans[i] %= 10;
	}	
	// 5.最高位是否有进位
	if(ans[l]) l ++;
	// 6.处理前导零
	// 特殊数据 ： 1. 0012 + 02 = 14  2. 000 + 0 = 0
	while(ans[l - 1] == 0 && l > 1) l --;
	// 7.倒序输出答案
	for (int i = l - 1; i >= 0; i --) cout << ans[i];
	return 0;
}