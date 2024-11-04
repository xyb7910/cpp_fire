#include <iostream>


void hanoiMove(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 1) {
        std::cout << "Move " << from_rod << " to " << to_rod << std::endl;
    } else {
        hanoiMove(n - 1, from_rod, aux_rod, to_rod);
        hanoiMove(1, from_rod, to_rod, aux_rod);
        hanoiMove(n - 1, aux_rod, to_rod, from_rod);
    }
}

 
int hanoiCountMoves(int n) {
    if (n == 1) {
        return 1;
    } else {
        return 2 * hanoiCountMoves(n - 1) + 1;
    }
}

int main() {
    int n;
    std::cin >> n; 

    std::cout << hanoiCountMoves(n) << std::endl;

    hanoiMove(n, 'A', 'C', 'B');

    return 0;
}



