#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>

using namespace std;
const int N = 1e9 + 10;
typedef long long LL;
double n;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n;
	double l = -1000, r = 1000;
	while(r - l > 0.0000001) {
		double mid = (l + r) / 2;
		if(mid * mid * mid < n) {
			l = mid;
		} else {
			r = mid;
		}
	}
	cout << fixed << setprecision(6) << l << endl;
	return 0;
}