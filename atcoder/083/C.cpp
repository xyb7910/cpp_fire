#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
LL x, y;
int main() {
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin >> x >> y;
	for (int  i = 0; i < 100; i ++) {
		LL temp = pow(2, i) * x;
		if(temp > y) {
			cout << i << endl;
			break;
		}
	}
	return 0;
}