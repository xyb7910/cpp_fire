#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int n, b;
int h[N];
int sum, cnt;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> b;
	for (int i = 0; i < n; i ++) cin >> h[i];
	sort(h, h + n);
	for (int i = n - 1; i >= 0; i --) {
		if(sum < b) {
			cnt ++;
			sum += h[i];
		}
	}
	cout << cnt << endl;
	return 0;
}