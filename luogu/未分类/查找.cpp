#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e6 + 10;
int n, m;
int num[N];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> num[i];
	while(m --) {
		int q;
		cin >> q;
		int index = lower_bound(num, num + n, q) - num;
		if(num[index] != q) cout << -1 << " ";
		else cout << index + 1 << " ";
	}
	return 0;
}
