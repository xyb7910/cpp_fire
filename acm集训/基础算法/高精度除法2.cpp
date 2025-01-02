/*
* @Author: Yanpb
* @Date:   2024-12-30 21:16:48
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-02 10:34:30
*/
// 计算 a / b 小数点后保留 n 位小数商的结果

#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

int main() {
	int a, b, n; cin >> a >> b >> n;
	cout << a / b << ".";
	int t = a % b;
	for (int i = 1; i <= n; i ++) {
		t *= 10;
		cout << t / b;
		t %= b;
	}
	return 0;
}
