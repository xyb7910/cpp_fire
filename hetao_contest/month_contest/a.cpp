#include <iostream>
#include <vector>
#include <string>

struct Exercise {
    std::string name;
    int start;
    int end;
    int tiredness;

    Exercise(std::string n, int s, int e, int t) : name(n), start(s), end(e), tiredness(t) {}
};

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<Exercise> exercises;
    for (int i = 0; i < m; ++i) {
        std::string name;
        int start, end, tiredness;
        std::cin >> name >> start >> end >> tiredness;
        exercises.push_back(Exercise(name, start, end, tiredness));
    }

    int currentStrength = n;
    bool canComplete = true;
    int minuteFailed = 0;

    for (int minute = 1; minute <= 1440 && canComplete; ++minute) {
 
        currentStrength += 1;


        for (const auto& ex : exercises) {
            if (minute >= ex.start && minute <= ex.end) {
                currentStrength -= ex.tiredness;
               
                if (currentStrength <= 0) {
                    canComplete = false;
                    minuteFailed = minute;
                    break; 
                }
            }
        }
    }

    if (canComplete) {
        std::cout << "Accepted" << std::endl;
        std::cout << currentStrength << std::endl;
    } else {
        std::cout << "Runtime Error" << std::endl;
        std::cout << minuteFailed << std::endl;
    }

    return 0;
}