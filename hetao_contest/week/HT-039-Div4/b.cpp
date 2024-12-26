/*
* @Author: Yanpb
* @Date:   2024-12-26 16:04:05
* @Last Modified by:   Hetao
* @Last Modified time: 2024-12-26 18:28:12
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
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

set<int> mod;
void solved() {
	/* your code */
	int n, k; cin >> n >> k;
	while(n --) {
		int num; cin >> num;
		int r = num % k;
		mod.insert(r);
	}
	cout << mod.size() << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}