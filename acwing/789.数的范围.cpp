#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;

typedef long long LL;
int n, q;
int num[N];

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i ++) cin >> num[i];

	while(q --) {
		int target;
		cin >> target;
		int l = 0, r = n - 1;
		while(l < r) {
			int mid = (l + r) >> 1;
			if(num[mid] < target) l = mid + 1;
			else r = mid;
		}
		if (num[l] != target) {
			cout << -1 << " " << -1 << endl;
		} else {
			cout << l << " ";
			r = n - 1;
			while(l < r) {
				int mid = (l + r + 1) >> 1;
				if(num[mid] > target) r = mid - 1;
				else l = mid;
			}
			cout << l << endl;
		    }
		}
	return 0;
}