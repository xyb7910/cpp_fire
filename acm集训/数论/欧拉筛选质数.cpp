#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

std::vector<int> get_primes(int n) {
	std::vector<int> primes(n); // 存储所有的 1 ～ n 的质数
	std::vector<bool> st(n); // 判断当前的数字 i 是否被筛选过
	int cnt = 0;
	for (int i = 2; i <= n; i ++) {
		if(!st[i]) primes[cnt ++] = i;
		for (int j = 0; primes[j] <= n / i; j ++) {
			st[primes[j] * i] = 1;
			if(!(i % primes[j])) break; // 只被最小的质数筛去
		}
	}
	return primes;
}

std::vector<int> getPrimes(int n) {
    std::vector<bool> isPrime(n + 1, true); // 如果对应的 i 是true，则表明 i 是质数
    std::vector<int> primes; // 存储所有的 1 ～ n 的质数
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= n; ++i) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
        for (int j = 0; j < primes.size() && i * primes[j] <= n; ++j) {
            isPrime[i * primes[j]] = false;
            if (i % primes[j] == 0) break; // 只被最小的质数筛去
        }
    }

    return primes;
}

int main() {
	int n; cin >> n;
	std::vector<int> ans = get_primes(n);
	for (auto a : ans) cout << a << " ";
	return 0;
}