/*
* @Author: Yanpb
* @Date:   2024-12-27 16:35:11
* @Last Modified by:   Yanpb
* @Last Modified time: 2024-12-27 18:15:46
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
const int N = 1e3 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n, maxv;
int cnt[N];

void solved() {
	/* your code */
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		int num; cin >> num;
		cnt[num] ++;
	}
	int target; cin >> target;
	cout << cnt[target] << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}