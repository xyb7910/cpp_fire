#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
LL n, m;
LL x, y, z;
LL res1, res2, ans1, ans2;

int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> n >> m;
	cin >> x >> y >> z;
	res1 = 2 * x + y; 
	res2 = y + 3 * z;
	ans1 = max(0LL, res1 - n);
	ans2 = max(0LL, res2 - m);
	cout <<  ans1 + ans2 << endl;
	return 0;
}