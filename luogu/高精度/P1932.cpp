/*
* @Author: Yanpb
* @Date:   2025-01-02 13:50:16
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-02 21:09:54
*/
// 计算和，差，积，商，余

#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long i64;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

string a, b;
int A[N], B[N], C[N], D[N], E[N], F[N], temp[N];
int l1, l2, l;

void add(int A[], int B[], int l) {
	// 首先计算加法
	for (int i = 0; i < l; i ++)
		C[i] = A[i] + B[i];
	// 在进行进位
	for (int i = 0; i < l; i ++) {
		C[i + 1] += C[i] / 10;
		C[i] %= 10;
	}
	// 考虑最高位的进位
	if(C[l]) l ++; 
	// 删除前导零
	while(C[l] == 0 && l > 0) l --;
	for (int i = l; i >= 0; i --) cout << C[i];
	cout << endl;
}


void sub(int A[], int B[], int l) {
	int t = 0;
	for (int i = 0; i < l; i ++) {
		int diff = A[i] - B[i] - t;
		if(diff < 0) {
			diff += 10;
			t = 1;
		} else {
			t = 0;
		}
		D[i] = diff;
	}
	// 删除前导零
	while(D[l] == 0 && l > 0) l --;
	for (int i = l; i >= 0; i --) cout << D[i];
	cout << endl;
}

void mul(int A[], int B[], int n, int m) {
	int l = n + m;
	// 首先进行乘法
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			E[i + j] += A[i] * B[i];
	// 再考虑进位
	for (int i = 0; i < l; i ++) {
		E[i + 1] += E[i] / 10;
		E[i] %= 10;
	}
	// 处理前导零
	while(E[l] == 0 && l > 0) l --;
	for (int i = l; i >= 0; i --) cout << E[i];
	cout << endl;
}

void div(int A[], int B[], int l) {
	for (int i = l - 1; i >= 0; i --) {
		memset(temp, 0, sizeof temp);

		// 向一个数后面追加 0
		for (int j = 0; j < l; j ++)  
	}
}

void solved() {
	/* your code */
	cin >> a >> b;
	int n = a.size(), m = b.size();
	for (int i = n - 1; i >= 0; i --) A[l1 ++] = a[i] - '0';
	for (int i = m - 1; i >= 0; i --) B[l2 ++] = b[i] - '0';

	// 高精度加法
	// 获取最大计算长度
	int l = max(l1, l2); 
	add(A, B, l);

	// 高精度减法
	bool neg = 0;
	if(n < m || n == m && a < b) neg = 1;
	if(neg) cout << "-";
	sub(A, B, l);

	// 高精度乘法
	mul(A, B, n, m);

	// 高精度除法
	l = n - m + 1;
	div(A, B, l);
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}