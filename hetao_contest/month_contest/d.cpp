#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    int n;
    std::cin >> n;

    std::vector<int> program(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> program[i];
    }


    int maxOutputIndex = 0;
    for (int i = 0; i < n; ++i) {
        if (program[i] > 0) {
            maxOutputIndex = std::max(maxOutputIndex, program[i]);
        }
    }


    std::vector<int> simplifiedProgram;
    int inputCount = 0;
    for (int i = 0; i < n; ++i) {
        if (program[i] == 0) {
           
            if (inputCount < maxOutputIndex) {
                simplifiedProgram.push_back(0);
                inputCount++;
            }
        } else {
           
            simplifiedProgram.push_back(program[i]);
        }
    }

    std::cout << simplifiedProgram.size() << std::endl;

    return 0;
}