/*
* @Author: Yanpb
* @Date:   2025-01-07 20:59:05
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-07 22:32:04
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

int res[N] = {1};

void solved() {
    /* your code */
    int n; cin >> n;

    int k = 1;
    for (int q = 1; q <= n + 1; q ++) {
    	for (int i = 0; i < k; i ++) res[i] *= 2;
	    for (int i = 0; i < k; i ++) {
	    	res[i + 1] += res[i] / 10;
	    	res[i] %= 10;
	    }
	    if(res[k]) k ++;
    }
    res[0] -= 2;
    for (int i = k - 1; ~i; i --) cout << res[i];
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}