/*
* @Author: Yanpb
* @Date:   2025-03-13 20:11:30
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-13 20:25:32
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
int n, res = 0x3f3f3f3f;
PII pos[N];
void solved() {
	/* your code */
	std::cin >> n;
	// 为了实现对 y 进行排序，这里做一个反向
	for (int i = 0; i < n; i ++) std::cin >> pos[i].y >> pos[i].x;
	sort(pos, pos + n);
	for (int i = pos[0].x; i <= pos[n - 1].x; i ++) {
		int minv = 0;
		for (int j = 0; j < n; j ++) {
			minv += abs(i - pos[j].x);
		}
		res = min(res, minv);
	}
	cout << res;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}