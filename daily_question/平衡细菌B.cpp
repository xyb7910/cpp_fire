/*
* @Author: Yanpb
* @Date:   2025-03-21 13:24:24
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-21 14:07:13
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
const int N = 2e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

i64 a[N], b[N], c[N];
i64 n, res;

void solved() {
	/* your code */
	scanf("%lld", &n);
	for (int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i ++) b[i] = a[i] - a[i - 1];
	for (int i = 1; i <= n; i ++) {
		c[i] = b[i] - b[i - 1];
		res += abs(c[i]);
	} 
	printf("%lld", res);
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}