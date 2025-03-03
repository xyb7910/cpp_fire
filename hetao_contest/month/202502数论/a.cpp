/*
* @Author: Yanpb
* @Date:   2025-03-02 14:17:41
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-02 14:38:20
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

i64 gcd(i64 a, i64 b) {
	return b ? gcd(b, a % b) : a;
}

i64 lcm(i64 a, i64 b) {
	return a * b == 0 ? 0 : a * b / gcd(a, b);
}

i64 a, b, c;
void solved() {
	/* your code */
	cin >> a >> b >> c;
	i64 res = lcm(a, b);
	res = lcm(res, c);
	cout << res << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}