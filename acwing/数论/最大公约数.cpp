#include <iostream>
using namespace std;

// 辗转相除法求最大公约数
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

int main() {
	int n; cin >> n;
	while(n --) {
		int a, b; cin >> a >> b;
		cout << gcd(a, b) << endl;
	}
	return 0;
}