#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int countNonZeroDigits(const string& num) {
    return count_if(num.begin(), num.end(), [](char c) { return c != '0'; });
}

int main() {
    string L, R;
    int k;
    cin >> L >> R >> k;  


    int intL = stoi(L);
    int intR = stoi(R);

    int bookCount = 0;
  
    for (int i = intL; i <= intR; ++i) {
        string bookNumber = to_string(i);
        bookNumber = string(5 - bookNumber.length(), '0') + bookNumber;
        if (countNonZeroDigits(bookNumber) == k) {
            bookCount++; 
        }
    }

    cout << bookCount << endl;

    return 0;
}