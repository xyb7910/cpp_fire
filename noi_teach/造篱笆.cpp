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
const int N = 1e6 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int v[N];

void solved() {
    /* your code */
    LL n;
    std::cin >> n;
    for (LL i = 1; i <= n; i ++) {
    	LL a;
    	std::cin >> a;
    	v[a] ++;
    }
    LL maxn = 0, ans = 0;
    for (LL i = 1; i <= 4001; i ++) {
    	LL sum = 0;
    	for (LL j = 1; j <= i; j ++) sum += min(v[j], v[i - j]);
    	if(maxn == sum) ans ++;
    	if(sum > maxn) maxn = sum, ans = 1;
    }
    std::cout << maxn / 2 << " " << ans << std::endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}