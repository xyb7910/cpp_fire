#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int n, m;
int L[N], R[N];

// 二分差异值
bool check(int k) {
	int cnt = 0;
	for (int i = 0, j = 0; i < n && j < m;) {
		if(abs(L[i] - R[j]) <= k) i ++, j ++, cnt ++;
		else if(L[i] > R[j]) j ++;
		else i ++;
	}
	return cnt == min(n, m);
}
	
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> L[i];
	for (int i = 0; i < m; i ++) cin >> R[i];

	sort(L, L + n);
	sort(R, R + m);

	int l = -1, r = 1e9;
	while(l  < r) {
		int mid = l + r >> 1;
		if(check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	cout << r << endl;
	return 0;
}