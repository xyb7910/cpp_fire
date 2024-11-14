#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		if(i % m == 0) continue;
		else cout << i << endl;
	}
	return 0;
}