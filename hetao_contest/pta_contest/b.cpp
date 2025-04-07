/*
* @Author: Yanpb
* @Date:   2025-04-07 12:50:13
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-04-07 16:11:01
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


void solved() {
	/* your code */
	string s;
	i64 n, k, a; cin >> n >> k;
	a = k ^ (k >> 1);
	for (int i = 0; i < n; i ++) {
		s = char(a % 2 + '0') + s;
		a /= 2;
	}
	cout << s;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}