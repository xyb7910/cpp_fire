#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
int a, b, c, d;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> a >> b >> c >> d;
	if (a + b < c + d) puts("Right");
	else if (a + b > c + d) puts("Left");
	else puts("Balanced ");
	return 0;
}