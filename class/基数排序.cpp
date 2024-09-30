#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int n, max_size, ans;
int num[N], cnt[N];
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> num[i];
		max_size = max(max_size, num[i]);
		cnt[num[i]] ++;	
	} 
	// for (int i = 0; i <= max_size; i ++) {
	// 	while(cnt[i] --) {
	// 		cout << i << " ";
	// 	}
	// }

	for (int i = 0; i <= max_size; i ++) {
		if(cnt[i]) {
			ans ++;
		}
	}
	cout << ans << endl;
	for (int i = 0; i <= max_size; i ++) {
		if(cnt[i]) {
			cout << i << " ";
		}
	}
	return 0;
}