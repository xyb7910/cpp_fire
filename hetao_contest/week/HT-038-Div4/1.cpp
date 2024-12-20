#include <iostream>

int main() {
    int m, n, k;
    std::cin >> m >> n >> k;
    int count = 0;
    while (m >= 2 && n >= 1 && m + n - 3 >= k) {
        m -= 2;
        n -= 1;
        count++;
    }
    std::cout << count << std::endl;
    return 0;
}