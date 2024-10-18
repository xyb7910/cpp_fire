#include <iostream>
#include <cstring>
#include <algorithm>
#include <unordered_set>
using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
int n, cnt, ans;
int num[N], ex[N];
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> num[i];
	for (int i = 1; i < n; i ++) {
		for (int j = 0; j <= i; j ++) {
			if(!ex[num[j]]) {
				ex[num[j]] ++;
				cnt ++;
			} else {
				memset(ex, sizeof(ex), 0);
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
	return 0;
}
