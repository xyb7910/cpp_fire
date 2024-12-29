/*
* @Author: Yanpb
* @Date:   2024-12-28 14:03:30
* @Last Modified by:   Yanpb
* @Last Modified time: 2024-12-28 14:30:26
*/
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

int A[N], B[N], C[N];
int l1, l2;

// 高精度加法 + 处理前导零
void solved() {
	/* your code */
	string a, b; cin >> a >> b;

	for (int i = a.size() - 1; ~i; i --) A[l1 ++] = a[i] - '0';
	for (int i = b.size() - 1; ~i; i --) B[l2 ++] = b[i] - '0';

	int l = max(a.size(), b.size());

	// 先加法
	for (int i = 0; i < l; i ++) {
		C[i] = A[i] + B[i];
	}
	// 处理进位
	for (int i = 0; i < l; i ++) {
		C[i + 1] += C[i] / 10;
		C[i] %= 10;
	}
	// 处理前导零
	while(C[l] == 0 && l > 0) l --;
	for (int i = l; ~i; i --) cout << C[i];
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}