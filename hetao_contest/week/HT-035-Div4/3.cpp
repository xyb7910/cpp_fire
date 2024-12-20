#include <iostream>
#include <string>

using namespace std;

int main() {
    string message;
    getline(cin, message); 

    int happyCount = 0;
    int sadCount = 0;

    for (int i = 0; i < message.length() - 2; ++i) {
        if (message.substr(i, 3) == ":-)") {
            happyCount++;
        } else if (message.substr(i, 3) == ":-(") {
            sadCount++;
        }
    }

    if (happyCount == 0 && sadCount == 0) {
        cout << "none" << endl;
    } else if (happyCount == sadCount) {
        cout << "unsure" << endl;
    } else if (happyCount > sadCount) {
        cout << "happy" << endl;
    } else {
        cout << "sad" << endl;
    }

    return 0;
}