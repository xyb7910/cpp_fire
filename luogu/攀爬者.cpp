#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int n;
struct point {
	int x, y, z;

	bool operator<(const point& t) {
		return z < t.z;
	}
};
point p[N];
double s;

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i ++)
		cin >> p[i].x >> p[i].y >> p[i].z;
	sort(p, p + n);
	for (int i = 1; i < n; i ++) {
		int dx = pow((p[i - 1].x - p[i].x), 2);
		int dy = pow((p[i - 1].y - p[i].y), 2);
		int dz = pow((p[i - 1].z - p[i].z), 2);
		s += sqrt(dx + dy + dz);
	}
	cout << fixed << setprecision(3) << s << endl;
	return 0;
}