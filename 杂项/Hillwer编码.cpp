/*
* @Author: Yanpb
* @Date:   2025-01-11 15:28:43
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-11 15:42:48
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

string s;
int A[N];

void solved() {
	/* your code */
	int n, r; cin >> n >> r;
	while(n --) {
		cin >> s;
		// 先处理中转码
		for (int i = 0 ; i < s.size(); i ++) {
			char c = s[i] + (r + 26) % 26;
			if(c >= 'A' && c <= 'Z') s[i] = c;
			else s[i] = c - 'Z' - 1 + 'A';
		}
		cout << s << endl;
		// 再处理符转数
		// 其实 高精度 * 低精度
		int l1 = 0, num = s[0];
		A[l1] = num % 10, A[++ l1] = num / 10;
		// q 表示s枚举到第几个字符
		for (int q = 1; q < s.size(); q ++) {
			int b = s[q];
			for (int i = 0; i <= l1; i ++) A[i] *= b;
			l1 += 2;
			for (int i = 0; i <= l1; i ++) {
				A[i + 1] += A[i] / 10;
				A[i] %= 10;
			}
			while(A[l1] == 0 && l1 > 0) l1 --;
		}
		for (int i = l1; ~i; i--) cout << A[i];
		cout << endl;
		memset(A, 0, sizeof A);
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}