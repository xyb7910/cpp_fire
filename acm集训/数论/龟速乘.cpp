#include <iostream>

using namespace std;
typedef long long LL;

LL trMuti(LL a, LL b, LL c) {
	LL res = 0;
	while(b) {
		if(b & 1) res = (res + a) % c;
		b >>= 1;
		a = (a + a) % c;
	}
	return res;
}

int main() {
	LL a, b, c; cin >> a >> b >> c;
	cout << trMuti(a, b, c) << endl;
	return 0;
}