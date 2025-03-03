/*
* @Author: Yanpb
* @Date:   2025-03-02 14:38:33
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-02 15:55:16
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

int num[40];

void solved() {
	/* your code */
	i64 res, rev_res = 0;
	cin >> res;
	for (int i = 1; i <= 32; i ++) {
		num[i] = res & 1;
		res >>= 1;
	}
	int p = 0;
	for (int i = 32; i >= 1; i --) {
		rev_res += num[i] * pow(2, p ++);
	}
	cout << rev_res << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; cin >> t; while(t --) solved();
    return 0;
}