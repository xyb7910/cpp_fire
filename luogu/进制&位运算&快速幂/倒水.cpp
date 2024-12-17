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

int lowbit(int x) {
	return x & -x;
}

int count_one(int x) {
	int cnt = 0;
	for (; x; x -= lowbit(x)) cnt ++;
	return cnt;
}

void solved() {
    /* your code */
    int n, k; cin >> n >> k;
    int ans = 0;
    while(count_one(n) > k) {
    	int t = lowbit(n);
    	ans += t;
    	n += t;
    }
    cout << ans << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}