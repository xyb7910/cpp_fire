#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int k, res;
int num[N];
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> k;
	for (int i = 0; i < k; i ++) cin >> num[i];
	sort(num, num + k);
	for (int i = 1; i < k; i ++) {
		res = max(res, num[i] - num[i - 1]);
	}
	cout << res << endl;
	return 0;
}