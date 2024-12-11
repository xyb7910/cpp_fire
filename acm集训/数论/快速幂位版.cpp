#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long LL;

LL qmi(LL a, LL k, LL p) {
	LL res = 1;
	while(k) {
		if(k & 1) res = (LL)res * a % p;
		k >>= 1;
		a = (LL) a * a % p;
	}
	return res;
}

int main() {
	int T=1; //cin >> T;
	while(T --) {
		LL a, b, p; cin >> a >> b >> p;
		cout << a <<"^" << b << " mod " << p << "=" << qmi(a, b, p) << endl;
	}
	return 0;
}