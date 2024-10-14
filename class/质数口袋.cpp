#include <iostream>
#include <vector>
#include <cmath>

// 判断素数
bool is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i <= x / i; i ++)
        if(x % i == 0) return false;
    return true;
}

int main() {
    int L;
    std::cin >> L;

    std::vector<int> primes;
    int sum = 0;

    for (int i = 2; i <= L; ++i) {
        if (is_prime(i)) {
            if (sum + i > L) break;
            primes.push_back(i);
            sum += i;
        }
    }

    for (int prime : primes) {
        std::cout << prime << std::endl;
    }
    std::cout << primes.size() << std::endl;

    return 0;
}