#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


int main() {
	int k, l, r;
	cin >> k >> l >> r;
	int sum = 0;
	for (int i = l; i <= r; i ++) {
		if (i % 10 == k || i % k == 0) sum += i; 
	}
	cout << sum;
	return 0;
}