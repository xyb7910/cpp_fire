#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int num[N];

int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i ++) cin >> num[i];
	int q; cin >> q;
	while(q --) {
		int target; cin >> target;
		int pos = lower_bound(num, num + n, target) - num;
		if(num[pos] == target) {
			cout << num[pos] << endl;
		} else {
			if(num[pos] - target > target - num[pos - 2]) {
				cout << num[pos - 2] << endl;
			} else {
				cout << num[pos] << endl;
			}
		}
		
	}
	return 0;
}