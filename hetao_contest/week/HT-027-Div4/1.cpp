#include <iostream>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <cmath>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
double a, b, c, d;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> a >> b >> c >> d;
	cout << fixed << setprecision(6);
	cout << sqrt(pow((a - c), 2) + pow(b - d, 2));
	return 0;
}