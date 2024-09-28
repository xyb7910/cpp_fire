#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
LL num[N], cnt[N];
int n, k;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i ++) {
		cin >> num[i];
		cnt[num[i] % k] ++;
	}

	int res = -1, ans = 0;
	for (int i = 0; i < k; i++) {
		if(res < cnt[i]) {
			res = cnt[i];
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}