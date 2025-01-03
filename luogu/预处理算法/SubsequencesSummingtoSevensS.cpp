/*
* @Author: Yanpb
* @Date:   2025-01-03 21:37:46
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-03 22:26:40
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
const int N = 1e6 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int s[N];

void solved() {
	/* your code */
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		int num; cin >> num;
		s[i] += (s[i - 1] + num) % 7;
	}
	for (int i = 1; i <= n; i ++) {
		cout << s[i] <<  " ";
	}
	int res = 0;
	for (int i = 1, j = n; i <= j; i ++, j --) {
		if(s[i] == s[j]) {
			res = max(res, j - i);
		}
	}
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}