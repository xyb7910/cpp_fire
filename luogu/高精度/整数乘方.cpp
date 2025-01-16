/*
* @Author: Yanpb
* @Date:   2025-01-08 00:30:50
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-16 18:33:52
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
    int a, n; cin >> a >> n;
    int k = 1;
    for (int i = 1; i <= n; i ++) {
    	for (int j = 0; j < k; j ++) res[j] *= a;
    	for (int j = 0; j < k; j ++) {
    		res[j + 1] += res[j] / 10;
    		res[j] %= 10;
    	}
    	if(res[k]) k ++;
    }
    int odd_cnt = 0;
    for (int i = 0; i < k; i ++) if(res[i] & 1) odd_cnt ++;
    cout << odd_cnt * 2 - k;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}