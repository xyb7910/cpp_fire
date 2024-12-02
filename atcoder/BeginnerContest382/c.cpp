#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 2e5 + 10;
typedef pair<int, int> PII;
int n, m; 
PII del[N];
int food[N];

int bs(int k) {
	int l = -1, r = n;
	while(l < r) {
		int mid = l + r >> 1;
		if(del[mid].x > k) r = mid;
		else l = mid + 1;
	}
	if(0 <= l && l < n) {
		return l;
	} else {
		return -1;
	}
}

int main() {
	cin >> n >> m;
	// for (auto &d : del) cin >> d;
	for (int i = 1; i <= n; i ++) {
		cin >> del[i].x;
		del[i].y = i;
	}
	sort(del, del + n);
	// for (int i = 0; i < n; i ++) cout << del[i].x << " ";
	for (auto &f : food) {
		cin >> f;
		cout << bs(f) << endl;
	} 
	return 0;
}