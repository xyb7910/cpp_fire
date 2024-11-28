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
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 2e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int cnt[N];
void solved() {
	/* your code */
	memset(cnt, 0, sizeof cnt);
	int n; cin >> n;
	for (int i = 0; i < n; i ++) {
		int num; cin >> num;
		cnt[num] ++;
	}
	int q = -1, p = -1;
	for (int i = 1; i <= n; i ++) {
		if(i * i == n - 2 && cnt[i] > 1) {
			p = i, q= i;
		} else if((n - 2) % i == 0) {
			if(cnt[i] && cnt[(n - 2) / i]) {
				p = i, q = (n - 2) / i;
			}
		}
	}
	cout << p << " " << q << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int t; cin >> t; while(t --) solved();
    return 0;
}