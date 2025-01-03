/*
* @Author: Yanpb
* @Date:   2025-01-03 16:40:47
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-03 18:35:18
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
	double a, b; cin >> a >> b;
	if(a > 0 && b > 0) cout << 1 << endl;
	else if(a > 0 && b < 0) cout << 4 << endl;
	else if(a < 0 && b > 0) cout << 2 << endl;
	else cout << 3 << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}