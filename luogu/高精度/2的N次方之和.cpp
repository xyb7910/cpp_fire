/*
* @Author: Yanpb
* @Date:   2024-12-31 11:22:15
* @Last Modified by:   Yanpb
* @Last Modified time: 2024-12-31 16:20:32
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

LL res[100] = {1}, ans[N] = {0};
void solved() {
    /* your code */
    int n; cin >> n;
    int k = 1, l = 1;
    for (int i = 1; i <= n; i ++) {
    	for (int j = 0; j < k; j ++) {
    		res[j] *= 2;
    	}

    	for (int j = 0; j < k; j ++) {
    		res[j + 1] += res[j] / 10;
    		res[j] %= 10;
    	}

    	if(res[k]) k ++;

    	l = max(l, k);
    	// 首先进行求和
    	for (int j = 0; j < l; j ++) 
    		ans[j] += res[j];
    	
    	for (int j = 0; j < l; j ++) {
    		ans[j + 1] += ans[j] / 10;
    		ans[j] %= 10;
    	}
    	if(ans[l]) l ++;
    }

    for (int i = l - 1; ~i; i --) cout << ans[i];
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}