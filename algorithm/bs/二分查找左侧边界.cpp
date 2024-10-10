#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e6 + 10;
typedef long long LL;
int n, p, target;
int num[N];

int binarySearch(int num[], int target) {
	int l = 0, r = n - 1;
	int res = -1;
	while(l <= r) {
		int mid = l + (r - l) / 2;
		if(num[mid] == target) {
			res = mid;
			r = mid - 1;
		}
		if(num[mid] < target) l = mid + 1;
		else r = mid - 1;
	}
	return res == -1 ? -1 : res + 1;
}

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> num[i];
	cin >> p;
	while(p --) {
		cin >> target;
		int pos = binarySearch(num, target);
		cout << pos << endl;
	}
	return 0;
}