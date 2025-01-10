#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;
const int N = 1e4 + 10;
int n, k;
double l[N];

bool check(int s) {
	int cnt = 0;
	for (int i = 0; i < n; i ++) {
		cnt += l[i] / s;
	}
	return cnt >= k;
}

int main() {
	cin >> n >> k;
	double num;
	for (int i = 0; i < n; i ++) {
		cin >> num;
		l[i] = 100.0 * num;
	} 
	double l = 0, r = 1 << 30;
	
	while(l <= r) {
		int mid = (l + r) / 2;
		if(check(mid)) l = mid + 1;
		else r = mid - 1;
	}

	cout << fixed << setprecision(2) << r / 100.0 << endl;
	return 0;
}