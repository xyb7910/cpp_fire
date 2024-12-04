#include <iostream>
using namespace std;

// 辗转相除法求最大公约数
int gcd(int a, int b) {
	return !b ? a : gcd(b, a % b);
}

// 利用最大公约数求最小公倍数
int lcm(int a, int b) {
    return a * b == 0 ? 0 : a * b / gcd(a, b);
}

int main() {
	int n; cin >> n;
	while(n --) {
		int a, b; cin >> a >> b;
		cout << lcm(a, b) << endl;
	}
	return 0;
}