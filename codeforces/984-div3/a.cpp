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
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int melo[N];

int solved() {
	/* your code */
	int T;
	cin >> T;
	while(T --) {
		int n;
		bool f = true;
		cin >> n;
		for (int i = 0; i < n; i ++) cin >> melo[i];

		for (int i = 1; i < n; i ++) {
			int me = abs(melo[i] - melo[i - 1]);
			if (me != 7 && me != 5) {
				f = false;
			}
		}
		if(f) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    return solved();
}