#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;
const int N = 1e5 + 10;
int n, k;
int l[N];

bool check(int s) {
	int cnt = 0;
	for (int i = 0; i < n; i ++) {
		cnt += l[i] / s;
	}
	return cnt >= k;
}

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i ++) {
		cin >> l[i];
	} 
	
	int l = 0, r = 1e8 + 10;
	while(l < r) {
		int mid = (l + r + 1) / 2;
		if(check(mid)) l = mid;
		else r = mid - 1;
	}

	cout << r << endl;
	return 0;
}