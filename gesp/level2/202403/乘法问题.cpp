#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int f = 1e6;
int main() {
	int n;
	cin >> n;
	int ans = 1;
	while(n --) {
		int num;
		cin >> num;
		ans *= num;
	}
	if(ans > f) cout << ">1000000";
	else cout << ans << endl;
	return 0;
}