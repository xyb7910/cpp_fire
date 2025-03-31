/*
* @Author: Yanpb
* @Date:   2025-03-06 14:03:03
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-06 14:12:05
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
const int N = 1e5 + 10, MOD = 10007;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void solved() {
	/* your code */
	int num; cin >> num;
	std::vector<int> res;
	for (int i = 1; i <= num / i; i ++) {
		if(num % i == 0) {
			res.push_back(i);
			if(i * i != num) res.push_back(num / i);
		}
	}
	i64 ans = 1;
	for (auto r : res) ans = (ans * r) % MOD;
	cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; cin >> t; while(t --) solved();
    return 0;
}