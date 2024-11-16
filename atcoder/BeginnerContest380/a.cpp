#include <iostream>
#include <array>

bool checkNumber(int N) {
    std::array<int, 10> counts = {0};  
    while (N > 0) {
        counts[N % 10]++;  
        N /= 10;  
    }

     
    return counts[1] == 1 && counts[2] == 2 && counts[3] == 3;
}

int main() {
    int N;
    std::cin >> N; 

  
    if (checkNumber(N)) {
        std::cout << "Yes" << std::endl;  
    } else {
        std::cout << "No" << std::endl;  
    }
    

    return 0;
}