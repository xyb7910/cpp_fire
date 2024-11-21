#include <iostream>

int main() {
    int n;  
    std::cin >> n;

    for (int i = 0; i < n; ++i) {
        int a, b;  
        std::cin >> a >> b;


        if ((a == 1 && b == 1) || (a == 0 && b == 0)) {
            std::cout << "Wrong" << std::endl;
        } else {
            std::cout << "Accepted" << std::endl;
        }
    }

    return 0;
}