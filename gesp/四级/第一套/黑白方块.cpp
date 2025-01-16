/*
* @Author: Yanpb
* @Date:   2025-01-13 23:18:39
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-01-15 12:29:53
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

int a[110][110], s[110][110];

bool equal(int x1, int y1, int x2, int y2) {
	int sum = s[x2][y2] - s[x2][y1 - 1] - s[x1 - 1][y2] + s[x1 - 1][y1 - 1];
	return 2 * sum == (x2 - x1 + 1) * (y2 - y1 + 1);
}

void solved() {
    /* your code */
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i ++)
    	for (int j = 1; j <= m; j ++) {
    		char c; cin >> c;
    		a[i][j] = c - '0';
    		s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];
    	}

    // 开始
    int ans = 0;
    for (int i = 1; i <= n; i ++)
    	for (int j = 1; j <= m; j ++)
    		for (int k = i; k <= n; k ++)
    			for (int l = j; l <= m; l ++) {
    				if(equal(i, j, k, l)) {
    					ans = max(ans, (k - i + 1) * (l - j + 1));
    				}
    			}	

    cout << ans << endl;	
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}