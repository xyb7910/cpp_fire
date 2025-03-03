/*
* @Author: Yanpb
* @Date:   2025-03-03 16:21:17
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-03 16:27:50
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
	int a, b, c, d, e, f, n, cnt = 0;
	cin >> a >> b >> c >> d >> e >> f >> n;
	int res1 = n % (a + b), res2 = n % (c + d), res3 = n % (e + f);
	if(res1 && res1 <= a) cnt ++;
	if(res2 && res2 <= c) cnt ++;
	if(res3 && res3 <= e) cnt ++;
	cout << cnt;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}