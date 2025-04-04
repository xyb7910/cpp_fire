#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <set>
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
LL n, m;
set<PII> s;

void solved() {
	/* your code */
	cin >> n >> m;
	while(m --) {
		int x, y;
		cin >> x >> y;
		s.insert({x ,y});
		for (int i = 0; i < 8; i ++) {
			int a = x + dxr[i], b = y + dyr[i];
			if(a > 0 && a <= n && b > 0 && b <= n) {
				s.insert({a, b});
			}
		}
	}
	cout << n * n - s.size() << endl;
}

int main() {
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    solved();
    return 0;
}