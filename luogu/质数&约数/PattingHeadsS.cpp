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
const int N = 1e6 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int cnt[N], cow[N];
void solved() {
	/* your code */
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		int num; cin >> num;
		cnt[num] ++;
		cow[i] = num;
	}
	
	for (int i = 1; i <= n; i ++) {
		LL res = -1;
		for (int j = 1; j <= cow[i] / j; j ++) {
			if(cow[i] % j == 0) {
				res += cnt[j] + cnt[cow[i] / j];
				if(j == cow[i] / j) res -= cnt[j];
			}
		}
		cout << res << endl;
	}

}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}