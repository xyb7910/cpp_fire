/*
* @Author: Yanpb
* @Date:   2025-03-02 14:28:14
* @Last Modified by:   Hetao
* @Last Modified time: 2025-03-02 14:37:28
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
i64 b, n, k;

i64 quick_pow(i64 a, i64 b, i64 p) {
	i64 res = 1;
	while(b) {
		if(b & 1) res = res * a % p;
		b >>= 1;
		a = a * a % p;
	}
	return res;
}

void solved() {
	/* your code */
	cin >> b >> n >> k;
	cout << quick_pow(b, n, k);
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}