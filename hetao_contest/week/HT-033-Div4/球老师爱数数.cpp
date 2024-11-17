#include <iostream>

using namespace std;

int main() {
	int n, x;
	cin >> n >> x;
	for (int i = 1; i <= n; i ++) {
		int num;
		cin >> num;
		cout << ((x & 1) == num ? x : ++ x) << " ";
		x ++;
	}
	return 0;
}