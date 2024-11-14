#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int x, y, z, q;
	cin >> x >> y >> z >> q;
	x = 2 * x + 5 * y + 3 * z;
	cout << (x <= q ? "Yes" : "No") << endl;
	cout << abs(q - x) << endl;
	return 0;
}