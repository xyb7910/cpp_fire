#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

std::vector<int> get_primes(int n) {
	std::vector<bool> st(n);  // 判断当前的数字 i 是否被筛选过
	std::vector<int> primes(n); // 存储所有的 1 ～ n 的质数
	int cnt = 0;
	for (int i = 2; i <= n;  i ++) {
		if(!st[i]) {
			primes[cnt ++] = i;
			for (int j = 2 * i; j <= n; j += i)
				st[j] = 1;
		}
	}
	return primes;
}

std::vector<int> getPrimes(int n) {
    std::vector<bool> prime(n + 1, true); // 如果对应的 i 是true，则表明 i 是质数
    std::vector<int> primes; // 存储所有的 1 ～ n 的质数
    prime[0] = prime[1] = false; 

    for (int p = 2; p * p <= n; p++) {
        if (prime[p] == true) {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }

    for (int p = 2; p <= n; p++) {
        if (prime[p]) {
            primes.push_back(p);
        }
    }

    return primes;
}

int main() {
	int n;
	cin >> n;
	std::vector<int> ans = get_primes(n);
	for (auto a : ans) cout << a << " ";
	return 0;
}