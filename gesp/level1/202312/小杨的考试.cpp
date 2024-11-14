#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
	int x, n;
	cin >> x >> n;
	int next = x + n % 7;
	cout <<  (next <= 7 ? next : next % 7) << endl;
	return 0;
}