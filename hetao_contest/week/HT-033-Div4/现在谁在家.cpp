#include <iostream>

void printStatus(bool isHome) {
    if (isHome) {
        std::cout << "at home" << std::endl;
    } else {
        std::cout << "not at home" << std::endl;
    }
}

bool isQingChengHome(int day, int hour) {
    return !((day == 1 || day == 4 || day == 5 || day == 6 || day == 7) && (hour >= 10 && hour < 19) ||
             (day == 2 || day == 3) && (hour >= 14 && hour < 17));
}

bool isJiangBingHome(int day, int hour) {
    return !((day >= 1 && day <= 5) && (hour >= 10 && hour < 19) ||
             ((day == 1 || day == 2 || day == 4 || day == 5 || day == 6) && (hour >= 19 && hour < 22)));
}

int main() {
    int day, hour;
    std::cin >> day >> hour;

    printStatus(isQingChengHome(day, hour));
    printStatus(isJiangBingHome(day, hour));

    return 0;
}