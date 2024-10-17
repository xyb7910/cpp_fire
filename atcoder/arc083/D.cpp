#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
char s[N];
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> s + 1;
	int n = strlen(s + 1);
	int ans = n;
	for (int i = 1; i < n;i ++) {
		if(s[i] != s[i + 1]) {
			ans = min(ans, max(i, n - i));
		}
	}
	cout << ans << endl;
	return 0;
}