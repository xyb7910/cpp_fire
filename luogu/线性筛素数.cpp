#include <iostream>
#include <vector>

using namespace std;

std::vector<int> get_primes(int n) {
	std::vector<int> primes(n);
	std::vector<bool> st(n);
	int cnt = 0;
	for (int i = 2; i <= n; i ++) {
		if(!st[i]) primes[cnt ++] = i;
		for (int j = 0; primes[j] <= n / i; j ++) {
			st[primes[j] * i] = 1;
			if(!(i % primes[j])) break;
		}
	}
	return primes;
}

int main() {
	int n, q; cin >> n >> q;
	std::vector<int> ans = get_primes(n);
	while(q --) {
		int num; cin >> num;
		cout << ans[num - 1] << endl;
	}
	return 0;
}