#include <iostream>
#include <vector>
#include <cmath>

// Function to use the Sieve of Eratosthenes to find all primes in a given range [L, R]
int sieveOfEratosthenes(int L, int R) {
    std::vector<bool> prime(R + 1, true); // Initialize all entries as true
    int sqrt_R = std::sqrt(R);
    int prime_count = 0;

    // Special case for 0 and 1
    if (L <= 1) prime[0] = false;
    if (L <= 2 && R >= 2) prime_count++;

    // Sieve of Eratosthenes
    for (int p = 2; p <= sqrt_R; ++p) {
        if (prime[p]) {
            for (int i = p * p; i <= R; i += p) {
                prime[i] = false;
            }
            // If p is greater than L, it's a prime in the range
            if (p >= L) prime_count++;
        }
    }

    // Count the primes in the range [L, R]
    for (int p = L; p <= R; ++p) {
        if (prime[p]) prime_count++;
    }

    return prime_count;
}

int main() {
    int L, R;
    std::cin >> L >> R;

    int prime_count = sieveOfEratosthenes(L, R);

    std::cout << prime_count << std::endl;

    return 0;
}