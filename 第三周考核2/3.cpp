#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
LL n, m, res, d1, d2;
LL line[N], score[N];

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> line[i];
	for (int i = 0; i < m; i ++) cin >> score[i];

	sort(line, line + n);
	sort(score, score + m);

	for (int i = 0; i < m; i ++) {
		LL l = 0, r = n;
		// 找到最大的小于
		while(l < r) {
			int mid = l + r + 1 >> 1;
			if(line[mid] <= score[i]) l = mid;
			else r = mid - 1;
		}

		if (line[l]) d1 = abs(line[l] - score[i]);
		else d1 = abs(score[i] - line[n - 1]);
		// cout << line[l] << " "<< d1 << " " << endl;

		l = 0, r = n;
		// 找到最小的大于
		while(l < r) {
			LL mid = l + r >> 1;
			if(line[mid] >= score[i]) r = mid;
			else l = mid + 1;
		}
		if (line[l]) d2 = abs(line[l] - score[i]);
		else d2 = abs(score[i] - line[n - 1]);
		// cout << line[l] << " "<< d2 << " ";

		res += min(d1, d2);
		
	}
	cout << res << endl;
	return 0;
}