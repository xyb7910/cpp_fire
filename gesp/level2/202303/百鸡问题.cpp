#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int x, y, z, cnt = 0;
	int n, m;
	cin >> x >> y >> z >> n >> m;
	for (int i = 0; i * x <= n && i <= m; i ++) {
		for (int j = 0; j * y + i * x <= n && i + j <= m; j ++) {
			int k = (n - i * x - j * y) * z;
			if(i + j + k == m) cnt ++;
		}
	}
	cout << cnt << endl;
	return 0;
}