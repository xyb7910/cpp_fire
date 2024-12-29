/*
* @Author: Yanpb
* @Date:   2024-12-28 14:09:28
* @Last Modified by:   Yanpb
* @Last Modified time: 2024-12-29 13:58:42
*/

// 定理 ： a * b = gcd(a, b) * lcm(a, b);

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

// 通过gcd ==> 最小公倍数
i64 gcd(i64 a, i64 b) {
	return b ? gcd(b, a % b) : a;
}

void solved() {
	/* your code */
	int n; cin >> n;
	i64 res; cin >> res;
	for (int i = 1; i < n; i ++) {
		i64 a; cin >> a;
		res = res / gcd(a, res) * a;
	}
	cout << res << endl; // result
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}