/*
* @Author: Yanpb
* @Date:   2025-03-31 12:49:18
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-31 13:01:48
*/
#include <iostream>

using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int n, q[N], a[N];

LL merge_sort(int q[], int l, int r) {
	if(l >= r) return 0;
	int mid = l + r >> 1;
	LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while(i <= mid && j <= r) {
		if(q[i] <= q[j]) a[k ++] = q[i ++];
		else  {
			res += mid - i + 1;
			a[k ++] = q[j ++];
		} 
	}
	while(i <= mid) a[k ++] = q[i ++];
	while(j <= r) a[k ++] = q[j ++];
	for (int i = l, j = 0; i <= r; i ++, j ++) q[i] = a[j];
	return res;
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> q[i];
	}
	cout << merge_sort(q, 0, n - 1);
	return 0;
}