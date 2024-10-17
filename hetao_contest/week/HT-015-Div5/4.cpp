#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#define x first
#define y second
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
typedef pair<int, int> PII;

int n, m;
PII a[N];
int cnt, ans;

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i ++) cin >> a[i].x;
	for (int i = 0; i < n; i ++) cin >> a[i].y;
	int start = 0, end = 1;
	std::vector<int> v;
	while(end < n) {
		end ++;
		if (a[start].x != a[end].x) {
			int sum = 0;
		for (int i = start; i < end; i ++){
			sum += a[i].y;
		} 
		ans += ceil(sum * 1.0 / m);
		start = end;
		cnt ++;
		} 
	}
	cout << cnt << endl;
	cout << ans << endl;
	return 0;
}