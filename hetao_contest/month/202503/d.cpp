/*
* @Author: Yanpb
* @Date:   2025-03-31 12:34:05
* @Last Modified by:   Yanpb
* @Last Modified time: 2025-03-31 14:19:42
*/
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

#define x first
#define y second

using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<double, double> PDD;
const int N = 1e5 + 10;
int dx4[4] = {-1, 0, 1, 0}, dy4[4] = {0, 1, 0, -1};
int dx8[8] = {-1, -1, -1, 0, 1, 1, 1, 0}, dy8[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dxr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dyr[8] = {1, 2, 2, 1, -1, -2, -2, -1};

int n; 
LL a[N], q[N];

LL merge_sort(LL q[], int l, int r) {
	if(l >= r) return 0;
	int mid = l + r >> 1;
	LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
	// merge_sort(q, l, mid), merge_sort(q, mid + 1, r);
	int k = 0, i = l, j = mid + 1;
	while(i <= mid && j <= r) {
		if(q[i] >= q[j]) a[k ++] = q[i ++];
		else {
			res += mid - i + 1;
			a[k ++] = q[j ++];
		}
	}
	while(i <= mid) a[k ++] = q[i ++];
	while(j <= r) a[k ++] = q[j ++];
	for (int i = l, j = 0; i <= r; i ++, j ++) q[i] = a[j];
	return res;
}

void solved() {
	/* your code */
	cin >> n;
	for (int i = 0; i < n; i ++) cin >> q[i];
	cout << merge_sort(q, 0, n - 1);
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}