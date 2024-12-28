/*
* @Author: Yanpb
* @Date:   2024-12-28 09:52:52
* @Last Modified by:   Yanpb
* @Last Modified time: 2024-12-28 09:56:48
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}

void solved() {
    /* your code */
    LL n, res = 1; cin >> n;
    for (int i = 1; i <= n; i ++) {
    	LL a; cin >> a;
    	res = res / gcd(res, a) * a;
    }
    cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}