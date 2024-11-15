#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

int checkmi(int x, int n) {
	int k = x, m = 0;
	while(x) {
		m += pow(x % 10, n);
		x /= 10;
	}
	return k == m;
}

int main() {
	int n;
	cin >> n;
	while(n --) {
		int num;
		cin >> num;
		int l = to_string(num).size();
		cout << (checkmi(num, l) ? "T" : "F") << endl;
	}
	return 0;
}